#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define FLAG_LEN 43

static const uint8_t raw_keys[4] = {0xA5, 0x5A, 0x3C, 0xC3};

static const uint8_t expected_state[43] = {
    0x6d, 0x72, 0xc0, 0x7b, 0xd2, 0xcf, 0xd6, 0xe1, 0xdb, 0x5f,
    0x7c, 0x80, 0xfa, 0x1, 0x71, 0x9f, 0x91, 0x8d, 0x96, 0x8e,
    0xad, 0x25, 0x2d, 0x34, 0x37, 0x36, 0x17, 0x51, 0x60, 0x57,
    0x2d, 0x64, 0x63, 0x73, 0x4c, 0x51, 0x52, 0x4c, 0x5d, 0x5a,
    0x91, 0x9d, 0x9b
};

static int execute_polymorphic_check(const char *input, size_t len) {
    if (len != FLAG_LEN) return 0;

    long page_size = sysconf(_SC_PAGESIZE);
    uint8_t *rwx_page = (uint8_t *)mmap(NULL, page_size, PROT_READ | PROT_WRITE | PROT_EXEC,
                                        MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (rwx_page == MAP_FAILED) {
        perror("mmap");
        return 0;
    }

    uint8_t state[FLAG_LEN];
    memcpy(state, input, FLAG_LEN);

    for (int round = 0; round < 4; round++) {
        uint8_t key = raw_keys[round];
        for (size_t i = 0; i < len; i++) {
            uint8_t shift = (uint8_t)(i * (round + 1) + 0x11);
            state[i] = (uint8_t)((state[i] ^ key) + shift);
        }

        memset(rwx_page, 0x90 + round, 256);
    }

    munmap(rwx_page, page_size);

    return (memcmp(state, expected_state, FLAG_LEN) == 0);
}

int main(int argc, char **argv) {
    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  KRONOS POLYMORPHIC SECURITY SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t len = strlen(input);
    if (execute_polymorphic_check(input, len)) {
        puts("[+] ACCESS GRANTED // POLYMORPHIC CORE COMPROMISED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Polymorphic Validation Failed!");
        return 1;
    }
}
