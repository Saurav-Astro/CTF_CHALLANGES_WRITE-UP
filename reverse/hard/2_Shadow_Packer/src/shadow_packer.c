#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ptrace.h>

#define PAYLOAD_SIZE 35

static const uint8_t packed_payload[35] = {
    0xd4, 0xa5, 0xeb, 0x24, 0x24, 0x23, 0x26, 0xb7, 0xb5, 0x1b, 0xa3, 0xcd, 0x96, 0x7e, 0x14, 0xb7, 0xbd, 0xa4, 0x83, 0x2b, 0x89, 0x5f, 0x41, 0x57, 0xfd, 0x29, 0x00, 0xf4, 0xd8, 0xa6, 0xa3, 0x88, 0xa1, 0x31, 0x67
};

static void verify_environment(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Environment Detected!");
        exit(42);
    }
}

static uint8_t *unpack_payload(void) {
    uint8_t *mem = (uint8_t *)mmap(NULL, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    uint32_t state = 0x13377331U;
    for (size_t i = 0; i < PAYLOAD_SIZE; i++) {
        state = (state * 1103515245U + 12345U) & 0xFFFFFFFFU;
        uint8_t key = (state >> 16) & 0xFFU;
        mem[i] = packed_payload[i] ^ key;
    }

    return mem;
}

int main(int argc, char **argv) {
    verify_environment();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  SHADOW PACKER // DYNAMIC RUNTIME UNPACKING SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != PAYLOAD_SIZE) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t *unpacked = unpack_payload();

    int success = 1;
    for (size_t i = 0; i < PAYLOAD_SIZE; i++) {
        if ((uint8_t)input[i] != unpacked[i]) {
            success = 0;
            break;
        }
    }

    munmap(unpacked, 4096);

    if (success) {
        puts("[+] ACCESS GRANTED // SHADOW PACKER UNPACKED & VERIFIED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Passcode!");
        return 1;
    }
}
