#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#define FLAG_LEN 36

static const uint16_t poly_expected[36] = {
    0x0032, 0x00ed, 0x00ad, 0x0030, 0x001f, 0x00c0, 0x00f5, 0x009e, 0x00cd, 0x0094, 0x00b8, 0x008f, 0x006f, 0x0050, 0x0079, 0x007b, 0x00bb, 0x00ec, 0x004d, 0x003a, 0x00e3, 0x0001, 0x00e1, 0x008e, 0x0004, 0x002a, 0x00dd, 0x00ee, 0x00d8, 0x0021, 0x0014, 0x0076, 0x0061, 0x008f, 0x00cb, 0x006e
};

static void verify_maps(void) {
    int fd = open("/proc/self/maps", O_RDONLY);
    if (fd >= 0) {
        char buf[4096];
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
        close(fd);
        if (n > 0) {
            buf[n] = '\0';
            if (strstr(buf, "ld.so.preload") || strstr(buf, "frida") || strstr(buf, "gdb")) {
                puts("[-] SECURITY ALERT: Hook Library Intercepted!");
                exit(88);
            }
        }
    }
}

int main(int argc, char **argv) {
    verify_maps();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  POLY XOR // MODULAR GF(257) POLYNOMIAL SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    for (size_t i = 0; i < FLAG_LEN; i++) {
        uint32_t val = (17U * (uint8_t)input[i] + 43U) % 257U;
        uint16_t res = (uint16_t)(val ^ ((i * 13 + 0x57) & 0xFFU));

        if (res != poly_expected[i]) {
            puts("[-] ACCESS DENIED: Polynomial Evaluation Mismatch!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // POLYNOMIAL SYSTEM UNLOCKED!");
    return 0;
}
