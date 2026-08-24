#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define FLAG_LEN 32

static const uint8_t xor_expected[32] = {
    0x32, 0x4d, 0x4b, 0x53, 0x5d, 0xe4, 0x0a, 0xfa, 0x5b, 0xba, 0x67, 0xff, 0xc5, 0x80, 0x87, 0x9f, 0xb5, 0xec, 0x59, 0xff, 0x3a, 0xb3, 0x1b, 0xf7, 0x5a, 0x67, 0x1d, 0x07, 0x5a, 0x3f, 0x3e, 0x34
};

static void verify_traceme(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Active!");
        exit(13);
    }
}

int main(int argc, char **argv) {
    verify_traceme();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  XOR CASCADE // CUMULATIVE XOR FEEDBACK SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t prev = 0x57;
    for (size_t i = 0; i < FLAG_LEN; i++) {
        uint8_t val = (uint8_t)input[i] ^ prev ^ ((i * 19 + 0x2A) & 0xFFU);
        if (val != xor_expected[i]) {
            puts("[-] ACCESS DENIED: Cascade Rejection!");
            return 1;
        }
        prev = val;
    }

    puts("[+] ACCESS GRANTED // XOR CASCADE UNLOCKED!");
    return 0;
}
