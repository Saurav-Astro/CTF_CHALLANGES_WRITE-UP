#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/ptrace.h>
#include <unistd.h>

#define PAYLOAD_LEN 36
#define EXPECTED_ADLER32 0x48c111f1U

static const uint8_t expected_payload[36] = {
    0x0d, 0x11, 0x32, 0x0e, 0xf6, 0xe5, 0x98, 0xcd, 0xfa, 0xb8, 0xdc, 0x91, 0x51, 0x2b, 0x54, 0x2d, 0x61, 0x11, 0x47, 0xb7, 0xc9, 0xc1, 0xca, 0xfd, 0xb7, 0xd8, 0xa3, 0x3b, 0x7d, 0x1d, 0x26, 0x68, 0x06, 0x42, 0xb0, 0xe8
};

#pragma pack(push, 1)
typedef struct {
    uint16_t magic;    // 0x5056 ('PV')
    uint8_t  command;  // 0x77 ('w')
    uint16_t length;   // Big-endian length
    uint32_t checksum; // Adler32 checksum
} packet_hdr_t;
#pragma pack(pop)

static void check_anti_debug(void) {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY ALERT: Debugger Process Intercepted!");
        exit(88);
    }
}

static uint32_t compute_adler32(const uint8_t *data, size_t len) {
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    for (size_t i = 0; i < len; i++) {
        s1 = (s1 + data[i]) % 65521U;
        s2 = (s2 + s1) % 65521U;
    }
    return (s2 << 16) | s1;
}

int main(int argc, char **argv) {
    check_anti_debug();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  PROTOCOL VAULT // CUSTOM BINARY FRAME PARSER\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    if (strlen(input) != PAYLOAD_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    uint8_t transformed[PAYLOAD_LEN];
    for (size_t i = 0; i < PAYLOAD_LEN; i++) {
        transformed[i] = (uint8_t)input[i] ^ ((i * 17 + 0x42) & 0xFFU);
    }

    uint32_t chk = compute_adler32(transformed, PAYLOAD_LEN);
    if (chk != EXPECTED_ADLER32) {
        puts("[-] ACCESS DENIED: Protocol Checksum Mismatch!");
        return 1;
    }

    if (memcmp(transformed, expected_payload, PAYLOAD_LEN) == 0) {
        puts("[+] ACCESS GRANTED // BINARY PROTOCOL VAULT UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Protocol Payload Mismatch!");
        return 1;
    }
}
