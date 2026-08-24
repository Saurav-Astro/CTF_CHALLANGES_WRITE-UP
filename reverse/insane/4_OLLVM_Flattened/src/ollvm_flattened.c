#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define FLAG_LEN 41

static const uint32_t exp_transforms[41] = {
    0x3b, 0x43, 0x3a, 0x70, 0x69, 0x6f, 0x7b, 0x78, 0x8e, 0x98,
    0xa2, 0xb7, 0xbd, 0xb5, 0xc0, 0xda, 0xec, 0xfc, 0x102, 0x104,
    0x107, 0x10e, 0x123, 0x13a, 0x140, 0x14e, 0x15c, 0x16a, 0x16b, 0x16a,
    0x183, 0x191, 0x193, 0x193, 0x1a1, 0x1a8, 0x1c7, 0x1d5, 0x1c6, 0x1e2,
    0x205
};

static uint32_t mba_add(uint32_t a, uint32_t b) {
    return (a ^ b) + 2 * (a & b);
}

static int verify_ollvm_flattened(const char *input, size_t len) {
    if (len != FLAG_LEN) return 0;

    int state = 0x10;
    int ok = 1;
    size_t idx = 0;

    while (state != 0x99) {
        switch (state) {
            case 0x10: {
                idx = 0;
                state = 0x20;
                break;
            }
            case 0x20: {
                if (idx >= len) {
                    state = 0x80;
                } else {
                    state = 0x30;
                }
                break;
            }
            case 0x30: {
                uint32_t c = (unsigned char)input[idx];
                uint32_t transform = mba_add(c ^ 0x57, idx * 11 + 0x23);

                if (transform != exp_transforms[idx]) {
                    ok = 0;
                    state = 0x90;
                } else {
                    idx++;
                    state = 0x20;
                }
                break;
            }
            case 0x80: {
                state = 0x99;
                break;
            }
            case 0x90: {
                ok = 0;
                state = 0x99;
                break;
            }
            default:
                state = 0x99;
                break;
        }
    }

    return ok;
}

int main(int argc, char **argv) {
    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  OLLVM FLATTENED MATRIX CORE SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t len = strlen(input);
    if (verify_ollvm_flattened(input, len)) {
        puts("[+] ACCESS GRANTED // OLLVM MATRIX DEFLATTENED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: OLLVM Verification Failed!");
        return 1;
    }
}
