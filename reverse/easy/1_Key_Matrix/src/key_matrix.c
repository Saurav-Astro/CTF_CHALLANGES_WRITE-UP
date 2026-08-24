#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define PADDED_LEN 34

static const uint8_t expected_matrix[34] = {
    0x37, 0x6c, 0x69, 0x09, 0x40, 0x3b, 0x46, 0x8b, 0x4b, 0x46, 0x96, 0x06, 0xeb, 0xaa, 0x26, 0x31, 0xb4, 0x5d, 0x6c, 0xd4, 0x74, 0xff, 0xa7, 0x42, 0x91, 0x2c, 0x37, 0x81, 0x7e, 0x0d, 0xa9, 0x3c, 0x77, 0xfa
};

static const uint8_t M[2][2] = {
    {3, 5},
    {2, 7}
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
        printf("  KEY MATRIX // 2x2 MOD 256 VECTOR SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != 33) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t padded[PADDED_LEN];
    memset(padded, 0, sizeof(padded));
    memcpy(padded, input, 33);

    uint8_t enc[PADDED_LEN];
    for (size_t i = 0; i < PADDED_LEN; i += 2) {
        uint32_t v0 = padded[i];
        uint32_t v1 = padded[i + 1];

        enc[i]     = (uint8_t)((M[0][0] * v0 + M[0][1] * v1) % 256);
        enc[i + 1] = (uint8_t)((M[1][0] * v0 + M[1][1] * v1) % 256);
    }

    if (memcmp(enc, expected_matrix, PADDED_LEN) == 0) {
        puts("[+] ACCESS GRANTED // KEY MATRIX UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Passcode!");
        return 1;
    }
}
