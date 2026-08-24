#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <fcntl.h>

#define NUM_BLOCKS 5
#define PAD_LEN (NUM_BLOCKS * 8)

static const uint32_t expected_blocks[10] = {
    0xdf0d878bU, 0xfbe6c496U,
    0x03a82140U, 0x8085e212U,
    0x5bb5325bU, 0xeb01dca6U,
    0x0d021258U, 0x961a6dd0U,
    0x8777f7edU, 0x85c36505U
};

static void check_anti_debugging(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY VIOLATION: Debugger Trapped!");
        exit(1337);
    }

    int fd = open("/proc/self/maps", O_RDONLY);
    if (fd >= 0) {
        char buf[4096];
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
        close(fd);
        if (n > 0) {
            buf[n] = '\0';
            if (strstr(buf, "ld.so.preload") || strstr(buf, "frida") || strstr(buf, "gdb")) {
                puts("[-] SECURITY VIOLATION: Instrumentation Library Trapped!");
                exit(1337);
            }
        }
    }
}

static uint32_t feistel_f(uint32_t r, uint32_t key) {
    uint32_t x = r ^ key;
    uint32_t rol3 = (x << 3) | (x >> 29);
    return rol3 + (r * 0x1F);
}

static void encrypt_block(uint32_t *left, uint32_t *right) {
    uint32_t l = *left;
    uint32_t r = *right;

    for (int round = 0; round < 32; round++) {
        uint32_t key = ((round * 0x01010101U) ^ (round * 13 + 0x37)) & 0xFFFFFFFFU;
        uint32_t next_l = r;
        uint32_t next_r = l ^ feistel_f(r, key);
        l = next_l;
        r = next_r;
    }

    *left = l;
    *right = r;
}

int main(int argc, char **argv) {
    check_anti_debugging();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  CIPHER LOCK // 32-ROUND FEISTEL CIPHER SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t in_len = strlen(input);
    if (in_len != 38) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t padded[PAD_LEN];
    memset(padded, 0, sizeof(padded));
    memcpy(padded, input, in_len);

    uint32_t blocks[10];
    for (int i = 0; i < NUM_BLOCKS; i++) {
        uint32_t b1, b2;
        memcpy(&b1, &padded[i * 8], 4);
        memcpy(&b2, &padded[i * 8 + 4], 4);
        encrypt_block(&b1, &b2);
        blocks[i * 2] = b1;
        blocks[i * 2 + 1] = b2;
    }

    if (memcmp(blocks, expected_blocks, sizeof(expected_blocks)) == 0) {
        puts("[+] ACCESS GRANTED // FEISTEL CIPHER UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Passcode!");
        return 1;
    }
}
