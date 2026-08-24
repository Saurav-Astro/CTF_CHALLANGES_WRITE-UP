#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define FLAG_LEN 37

typedef struct {
    uint8_t code;
    uint8_t dst_reg;
    uint8_t src_reg;
    int16_t off;
    int32_t imm;
} EbpfInsn;

#define BPF_ALU64 0x07
#define BPF_XOR   0xa0
#define BPF_ADD   0x00
#define BPF_SUB   0x10

static EbpfInsn ebpf_kernel_filter[] = {
    { BPF_ALU64 | BPF_XOR, 0, 0, 0, 0x42 },
    { BPF_ALU64 | BPF_ADD, 0, 0, 0, 0x19 },
    { BPF_ALU64 | BPF_SUB, 0, 0, 0, 0x05 }
};

static const uint8_t ebpf_expected[37] = {
    0x21, 0x10, 0x20, 0x41, 0xb, 0x0, 0xe, 0xfc, 0x11, 0xf9,
    0xf3, 0xf8, 0xf0, 0xe7, 0xea, 0xf5, 0xe4, 0xdb, 0xd8, 0xcd,
    0xe1, 0xd4, 0xc3, 0xc8, 0xbf, 0xb4, 0xb7, 0xaf, 0xb4, 0xbd,
    0xa3, 0xa9, 0x95, 0x93, 0x9e, 0x8f, 0xc3
};

static int run_ebpf_verifier_vm(const char *input, size_t len) {
    if (len != FLAG_LEN) return 0;

    for (size_t i = 0; i < len; i++) {
        uint8_t val = (uint8_t)input[i];

        val = (val ^ 0x42);
        val = (val + (uint8_t)(i * 3 + 0x19));
        val = (val - (uint8_t)(i * 7 + 0x05));

        if (val != ebpf_expected[i]) return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  KERNEL PHANTOM // EBPF VERIFIER SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t len = strlen(input);
    if (run_ebpf_verifier_vm(input, len)) {
        puts("[+] ACCESS GRANTED // EBPF KERNEL RING UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: eBPF Verifier Rejected Input!");
        return 1;
    }
}
