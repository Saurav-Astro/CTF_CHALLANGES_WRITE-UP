#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define FLAG_LEN 39

static const uint8_t vm_expected[39] = {
    0xdc, 0xdc, 0xf1, 0x72, 0x8a, 0xd3, 0xd1, 0x86, 0x9f, 0x98, 0xbf, 0xbf, 0x1d, 0x06, 0xe0, 0xde, 0x7f, 0x86, 0x3f, 0x4c, 0xd4, 0x42, 0xb3, 0xfa, 0x43, 0xa4, 0x22, 0x74, 0xa1, 0x62, 0x23, 0xce, 0x78, 0x76, 0x7d, 0xa7, 0x55, 0x5e, 0x3e
};

enum Opcodes {
    OP_READ_INPUT = 0x01,
    OP_XOR_IMM    = 0x02,
    OP_ADD_IMM    = 0x03,
    OP_ROL_IMM    = 0x04,
    OP_CMP_EXP    = 0x05,
    OP_HALT       = 0x06
};

static void verify_traceme(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Trapped!");
        exit(66);
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
        printf("  BYTECODE CHECKER // MINI VM INTERPRETER SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    // Run VM bytecode loop
    for (size_t i = 0; i < FLAG_LEN; i++) {
        uint8_t reg = (uint8_t)input[i];                // OP_READ_INPUT
        reg ^= ((i * 11 + 0x33) & 0xFFU);              // OP_XOR_IMM
        reg = (reg + 0x1FU) & 0xFFU;                    // OP_ADD_IMM
        reg = rol8(reg, 3);                             // OP_ROL_IMM

        if (reg != vm_expected[i]) {                    // OP_CMP_EXP
            puts("[-] ACCESS DENIED: Virtual Machine Rejection!");
            return 1;
        }
    }

    puts("[+] ACCESS GRANTED // BYTECODE CHECKER UNLOCKED!");
    return 0;
}
