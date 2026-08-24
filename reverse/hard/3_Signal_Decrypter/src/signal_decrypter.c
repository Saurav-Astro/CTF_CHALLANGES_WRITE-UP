#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define SIGNAL_LEN 33

static const uint8_t signal_expected[33] = {
    0xf0, 0x58, 0x3b, 0x0d, 0x5a, 0x9c, 0x81, 0x0c, 0x17, 0x22, 0xf0, 0x4c, 0xb8, 0xf6, 0x3d, 0x08, 0x3d, 0x1e, 0x80, 0xa2, 0x1d, 0x4f, 0xe4, 0x3d, 0x8a, 0x24, 0xb1, 0x18, 0x78, 0x61, 0xaf, 0xad, 0x4c
};

static void verify_traceme(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Anti-Debugging Triggered!");
        exit(99);
    }
}

static __attribute__((noinline)) void anti_disasm_hook(void) {
    __asm__ volatile (
        "jmp 1f\n\t"
        ".byte 0xE8\n\t"
        "1:\n\t"
    );
}

static int verify_signal(const char *input) {
    anti_disasm_hook();
    uint64_t state = 0x9E3779B97F4A7C15ULL;

    for (size_t i = 0; i < SIGNAL_LEN; i++) {
        state = (state * 6364136223846793005ULL + 1442695040888963407ULL);
        uint8_t k = (state >> 24) & 0xFFU;
        if (((uint8_t)input[i] ^ k) != signal_expected[i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    verify_traceme();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  SIGNAL DECRYPTER // STATEFUL STREAM CIPHER SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Signal: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != SIGNAL_LEN) {
        puts("[-] ACCESS DENIED: Invalid Signal Length!");
        return 1;
    }

    if (verify_signal(input)) {
        puts("[+] ACCESS GRANTED // SIGNAL DECRYPTED & AUTHENTICATED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Signal!");
        return 1;
    }
}
