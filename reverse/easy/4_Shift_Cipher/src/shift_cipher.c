#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define FLAG_LEN 32

static const uint8_t shift_expected[32] = {
    0xea, 0xe1, 0x63, 0x14, 0xe1, 0xa4, 0x2c, 0xe2, 0xe4, 0xac, 0xb2, 0x2c, 0x52, 0x25, 0x21, 0x90, 0x95, 0xc2, 0xb0, 0xc9, 0x9a, 0x2c, 0x78, 0x90, 0xac, 0x14, 0x09, 0x70, 0xc5, 0x61, 0x10, 0x1d
};

static void verify_traceme(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Active!");
        exit(13);
    }
}

static uint8_t rol8(uint8_t val, int r) {
    r = r % 8;
    return (uint8_t)((val << r) | (val >> (8 - r)));
}

int main(int argc, char **argv) {
    verify_traceme();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  SHIFT CIPHER // CIRCULAR BIT SHIFT SYSTEM\n");
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
        int r = (i % 5) + 1;
        uint8_t val = rol8((uint8_t)input[i] ^ 0x3AU, r);
        if (val != shift_expected[i]) {
            puts("[-] ACCESS DENIED: Shift Cipher Rejection!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // SHIFT CIPHER UNLOCKED!");
    return 0;
}
