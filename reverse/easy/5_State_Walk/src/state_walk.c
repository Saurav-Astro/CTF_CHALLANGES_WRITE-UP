#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define FLAG_LEN 30

static const uint8_t walk_expected[30] = {
    0x0d, 0x44, 0x20, 0xb0, 0xe1, 0x76, 0x28, 0x8d, 0xe6, 0x78, 0xc5, 0x44, 0x84, 0x42, 0x83, 0x1e, 0xfb, 0x10, 0xbe, 0x4c, 0x8c, 0x8b, 0x41, 0x4e, 0x49, 0xac, 0xb5, 0x40, 0x68, 0x20
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
        printf("  STATE WALK // ACCUMULATOR AUTOMATON SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t state = 0x42;
    for (size_t i = 0; i < FLAG_LEN; i++) {
        state = state ^ (((uint8_t)input[i] + i * 7) & 0xFFU);
        if (state != walk_expected[i]) {
            puts("[-] ACCESS DENIED: State Accumulator Rejection!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // STATE WALK UNLOCKED!");
    return 0;
}
