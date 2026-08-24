#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#define FLAG_LEN 38

static const uint8_t prng_expected[38] = {
    0xec, 0x1e, 0x5c, 0xd1, 0x8b, 0xc3, 0xc4, 0xae, 0x37, 0xd4, 0x74, 0xf8, 0x46, 0x5f, 0x98, 0x80, 0x4c, 0x14, 0xde, 0x21, 0x7b, 0x10, 0xe7, 0xcd, 0xbe, 0xb2, 0xe7, 0x03, 0x67, 0x7a, 0x45, 0xfb, 0x44, 0x79, 0xce, 0xdb, 0xe1, 0x3c
};

// Xorshift128 state
static uint32_t x = 123456789U;
static uint32_t y = 362436069U;
static uint32_t z = 521288629U;
static uint32_t w = 88675123U;

static uint32_t xorshift128(void) {
    uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    return w;
}

static void verify_tracerpid(void) {
    int fd = open("/proc/self/status", O_RDONLY);
    if (fd >= 0) {
        char buf[2048];
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
        close(fd);
        if (n > 0) {
            buf[n] = '\0';
            char *p = strstr(buf, "TracerPid:");
            if (p) {
                int pid = atoi(p + 10);
                if (pid > 0) {
                    puts("[-] SECURITY ALERT: TracerPid Debugger Active!");
                    exit(77);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    verify_tracerpid();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  CUSTOM PRNG // XORSHIFT128 STREAM SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Key: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    for (size_t i = 0; i < FLAG_LEN; i++) {
        uint8_t k = (xorshift128() >> 16) & 0xFFU;
        uint8_t enc = (uint8_t)input[i] ^ k ^ ((i * 13) & 0xFFU);
        if (enc != prng_expected[i]) {
            puts("[-] ACCESS DENIED: Keystream Mismatch!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // XORSHIFT128 PRNG UNLOCKED!");
    return 0;
}
