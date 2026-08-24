#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define FLAG_LEN 33

static const uint8_t swapper_expected[33] = {
    0xb5, 0x6c, 0x2a, 0xe1, 0x7b, 0xf3, 0x2c, 0x41, 0x8c, 0xd3, 0xf0, 0xcd, 0x92, 0x9b, 0x90, 0x8d, 0x44, 0x5e, 0xac, 0xe0, 0xeb, 0x12, 0xe8, 0x17, 0x6e, 0xf3, 0xd0, 0x0b, 0x96, 0x2f, 0x55, 0x69, 0xf6
};

static void verify_traceme(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Active!");
        exit(13);
    }
}

static uint8_t swap_nibbles(uint8_t b) {
    return (uint8_t)(((b & 0x0FU) << 4) | ((b & 0xF0U) >> 4));
}

int main(int argc, char **argv) {
    verify_traceme();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  BYTE SWAPPER // NIBBLE PERMUTATION SYSTEM\n");
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
        uint8_t val = swap_nibbles((uint8_t)input[i]) ^ ((i * 7 + 0x41) & 0xFFU);
        if (val != swapper_expected[i]) {
            puts("[-] ACCESS DENIED: Nibble Swapper Rejection!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // BYTE SWAPPER UNLOCKED!");
    return 0;
}
