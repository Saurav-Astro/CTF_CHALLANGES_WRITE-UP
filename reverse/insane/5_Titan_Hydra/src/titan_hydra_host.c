#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define FLAG_LEN 36

static const uint8_t triad_expected[36] = {
    0xab, 0x25, 0x2e, 0x7a, 0x68, 0x45, 0x19, 0xe2, 0x96, 0x5c, 0x9a, 0xd1,
    0x26, 0xb1, 0xd3, 0xf8, 0xff, 0xe0, 0x24, 0xe2, 0xdc, 0xcb, 0x95, 0xd2,
    0xf6, 0x8a, 0xc5, 0xf, 0x92, 0x74, 0x1e, 0x76, 0x23, 0xb5, 0xaf, 0x76
};

static void x86_host_transform(uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; i++) {
        buf[i] = (uint8_t)((buf[i] ^ (i * 9 + 0x17)) + (i * 3 + 0x11));
    }
}

static void wasm_module_transform(uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; i++) {
        buf[i] = (uint8_t)(((buf[i] << 4) | (buf[i] >> 4)) ^ (i * 5 + 0x3D));
    }
}

static void arm64_child_process(int socket_fd) {
    uint8_t buf[FLAG_LEN];
    ssize_t n = read(socket_fd, buf, sizeof(buf));
    if (n != FLAG_LEN) {
        uint8_t status = 0;
        write(socket_fd, &status, 1);
        exit(1);
    }

    uint8_t status = (memcmp(buf, triad_expected, FLAG_LEN) == 0) ? 1 : 0;
    write(socket_fd, &status, 1);
    close(socket_fd);
    exit(0);
}

int main(int argc, char **argv) {
    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  TITAN HYDRA // MULTI-ARCH IPC TRIAD\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) return 1;
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t len = strlen(input);
    if (len != FLAG_LEN) {
        puts("[-] ACCESS DENIED: Invalid Passcode Length!");
        return 1;
    }

    int sv[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) < 0) {
        perror("socketpair");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(sv[0]);
        arm64_child_process(sv[1]);
    } else {
        close(sv[1]);

        uint8_t payload[FLAG_LEN];
        memcpy(payload, input, FLAG_LEN);

        x86_host_transform(payload, FLAG_LEN);
        wasm_module_transform(payload, FLAG_LEN);

        write(sv[0], payload, FLAG_LEN);

        uint8_t status = 0;
        read(sv[0], &status, 1);
        close(sv[0]);
        waitpid(pid, NULL, 0);

        if (status == 1) {
            puts("[+] ACCESS GRANTED // TRIAD ARCHITECTURE COMPROMISED!");
            return 0;
        } else {
            puts("[-] ACCESS DENIED: Triad Validation Rejected!");
            return 1;
        }
    }

    return 0;
}
