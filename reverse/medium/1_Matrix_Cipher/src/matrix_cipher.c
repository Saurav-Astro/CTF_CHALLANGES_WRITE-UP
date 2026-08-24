#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define PADDED_LEN 39

static const uint8_t expected_matrix[39] = {
    0xd5, 0x9a, 0x17, 0xf1, 0x3d, 0xf5, 0xeb, 0x36, 0xf0, 0x7d, 0x13, 0x92, 0xa9, 0x3c, 0xd1, 0x55, 0x20, 0x95, 0x93, 0x33, 0x47, 0x66, 0xf1, 0x6a, 0x73, 0x13, 0x60, 0x8e, 0x2c, 0x48, 0xbe, 0xb2, 0x4d, 0x94, 0x2e, 0x5f, 0x5b, 0x7d, 0xd3
};

static const uint8_t M[3][3] = {
    {1, 2, 3},
    {0, 1, 4},
    {5, 6, 0}
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
        printf("  MATRIX CIPHER // 3x3 MOD 256 VECTOR SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != 38) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t padded[PADDED_LEN];
    memset(padded, 0, sizeof(padded));
    memcpy(padded, input, 38);

    uint8_t enc[PADDED_LEN];
    for (size_t i = 0; i < PADDED_LEN; i += 3) {
        uint32_t v0 = padded[i];
        uint32_t v1 = padded[i + 1];
        uint32_t v2 = padded[i + 2];

        enc[i]     = (uint8_t)((M[0][0] * v0 + M[0][1] * v1 + M[0][2] * v2) % 256);
        enc[i + 1] = (uint8_t)((M[1][0] * v0 + M[1][1] * v1 + M[1][2] * v2) % 256);
        enc[i + 2] = (uint8_t)((M[2][0] * v0 + M[2][1] * v1 + M[2][2] * v2) % 256);
    }

    if (memcmp(enc, expected_matrix, PADDED_LEN) == 0) {
        puts("[+] ACCESS GRANTED // MATRIX CIPHER UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Passcode!");
        return 1;
    }
}
