#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <x86intrin.h>

#define OP_PUSH_IMM    0x10
#define OP_PUSH_INPUT  0x11
#define OP_POP         0x20
#define OP_ADD         0x30
#define OP_SUB         0x31
#define OP_XOR         0x32
#define OP_ROL3        0x33
#define OP_MUL_CONST   0x34
#define OP_CHECK_EQ    0x40
#define OP_HALT        0x50

#define VM_STACK_SIZE 256

typedef struct {
    uint32_t stack[VM_STACK_SIZE];
    int sp;
    int pc;
    int status;
} VMState;

static const uint32_t expected_checks[36] = {
    0x2e0, 0x103a, 0xffffffc8, 0x298, 0x1512, 0xffffffbb,
    0x370, 0x1bda, 0xfffffffa, 0xf8, 0x21e8, 0xffffff90,
    0x150, 0x26a1, 0xffffff88, 0x160, 0x27f6, 0xffffff75,
    0x6a8, 0x2ced, 0xffffff74, 0x750, 0x3222, 0xffffff5a,
    0x778, 0x36db, 0xffffff43, 0x4b8, 0x3e3e, 0xffffff3f,
    0x520, 0x4183, 0xffffff25, 0x648, 0x461d, 0xffffff3e
};

static unsigned char bytecode[512];
static size_t bytecode_len = 0;

static void check_anti_analysis(void) {
    // 1. ptrace check
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        puts("[-] SECURITY VIOLATION: Debugger Detected (PTRACE)!");
        exit(1337);
    }

    // 2. TracerPid check in /proc/self/status
    int fd = open("/proc/self/status", O_RDONLY);
    if (fd >= 0) {
        char buf[2048];
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
        close(fd);
        if (n > 0) {
            buf[n] = '\0';
            char *tracer = strstr(buf, "State:\tTrace");
            if (tracer) {
                puts("[-] SECURITY VIOLATION: Active Debugger Trapped!");
                exit(1337);
            }
        }
    }

    // 3. Timing Check using rdtsc
    unsigned long long t1 = __rdtsc();
    for (volatile int i = 0; i < 10000; i++);
    unsigned long long t2 = __rdtsc();
    if ((t2 - t1) > 10000000ULL) {
        puts("[-] SECURITY VIOLATION: Timing Anomaly Detected!");
        exit(1337);
    }
}

static void sigtrap_handler(int sig) {
    (void)sig;
}

static void init_vm_program(size_t len) {
    size_t pos = 0;

    for (size_t i = 0; i < len; i++) {
        if (i % 3 == 0) {
            bytecode[pos++] = OP_PUSH_INPUT;
            uint32_t idx = (uint32_t)i;
            memcpy(&bytecode[pos], &idx, 4); pos += 4;

            bytecode[pos++] = OP_PUSH_IMM;
            uint32_t k = (uint32_t)(i * 7 + 0x13);
            memcpy(&bytecode[pos], &k, 4); pos += 4;

            bytecode[pos++] = OP_XOR;
            bytecode[pos++] = OP_ROL3;
        } else if (i % 3 == 1) {
            bytecode[pos++] = OP_PUSH_INPUT;
            uint32_t idx = (uint32_t)i;
            memcpy(&bytecode[pos], &idx, 4); pos += 4;

            bytecode[pos++] = OP_PUSH_IMM;
            uint32_t k = (uint32_t)(i * 13 + 0x37);
            memcpy(&bytecode[pos], &k, 4); pos += 4;

            bytecode[pos++] = OP_ADD;
            bytecode[pos++] = OP_MUL_CONST;
            uint32_t m = 0x1F;
            memcpy(&bytecode[pos], &m, 4); pos += 4;
        } else {
            bytecode[pos++] = OP_PUSH_INPUT;
            uint32_t idx = (uint32_t)i;
            memcpy(&bytecode[pos], &idx, 4); pos += 4;

            bytecode[pos++] = OP_PUSH_INPUT;
            uint32_t idx_prev = (uint32_t)(i - 1);
            memcpy(&bytecode[pos], &idx_prev, 4); pos += 4;

            bytecode[pos++] = OP_XOR;

            bytecode[pos++] = OP_PUSH_IMM;
            uint32_t k = (uint32_t)(i * 5 + 0x42);
            memcpy(&bytecode[pos], &k, 4); pos += 4;

            bytecode[pos++] = OP_SUB;
        }

        bytecode[pos++] = OP_CHECK_EQ;
        uint32_t c_idx = (uint32_t)i;
        memcpy(&bytecode[pos], &c_idx, 4); pos += 4;
    }

    bytecode[pos++] = OP_HALT;
    bytecode_len = pos;
}

static int run_vm(const char *input, size_t input_len) {
    VMState vm;
    vm.sp = 0;
    vm.pc = 0;
    vm.status = 1;

    while (vm.pc < (int)bytecode_len && vm.status) {
        unsigned char op = bytecode[vm.pc++];
        switch (op) {
            case OP_PUSH_IMM: {
                uint32_t val;
                memcpy(&val, &bytecode[vm.pc], 4);
                vm.pc += 4;
                vm.stack[vm.sp++] = val;
                break;
            }
            case OP_PUSH_INPUT: {
                uint32_t idx;
                memcpy(&idx, &bytecode[vm.pc], 4);
                vm.pc += 4;
                if (idx < input_len) {
                    vm.stack[vm.sp++] = (unsigned char)input[idx];
                } else {
                    vm.stack[vm.sp++] = 0;
                }
                break;
            }
            case OP_POP: {
                if (vm.sp > 0) vm.sp--;
                break;
            }
            case OP_ADD: {
                if (vm.sp >= 2) {
                    uint32_t b = vm.stack[--vm.sp];
                    uint32_t a = vm.stack[--vm.sp];
                    vm.stack[vm.sp++] = a + b;
                }
                break;
            }
            case OP_SUB: {
                if (vm.sp >= 2) {
                    uint32_t b = vm.stack[--vm.sp];
                    uint32_t a = vm.stack[--vm.sp];
                    vm.stack[vm.sp++] = a - b;
                }
                break;
            }
            case OP_XOR: {
                if (vm.sp >= 2) {
                    uint32_t b = vm.stack[--vm.sp];
                    uint32_t a = vm.stack[--vm.sp];
                    vm.stack[vm.sp++] = a ^ b;
                }
                break;
            }
            case OP_ROL3: {
                if (vm.sp >= 1) {
                    uint32_t v = vm.stack[--vm.sp];
                    vm.stack[vm.sp++] = (v << 3) | (v >> 29);
                }
                break;
            }
            case OP_MUL_CONST: {
                uint32_t m;
                memcpy(&m, &bytecode[vm.pc], 4);
                vm.pc += 4;
                if (vm.sp >= 1) {
                    vm.stack[vm.sp - 1] *= m;
                }
                break;
            }
            case OP_CHECK_EQ: {
                uint32_t idx;
                memcpy(&idx, &bytecode[vm.pc], 4);
                vm.pc += 4;
                if (vm.sp >= 1) {
                    uint32_t val = vm.stack[--vm.sp];
                    if (val != expected_checks[idx]) {
                        vm.status = 0;
                    }
                } else {
                    vm.status = 0;
                }
                break;
            }
            case OP_HALT: {
                return vm.status;
            }
            default:
                vm.status = 0;
                return 0;
        }
    }
    return vm.status;
}

int main(int argc, char **argv) {
    signal(SIGTRAP, sigtrap_handler);
    check_anti_analysis();

    char input[128];
    if (argc > 1) {
        strncpy(input, argv[1], sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    } else {
        printf("====================================================\n");
        printf("  PROJECT OBLIVION // CUSTOM VM ACCESS SYSTEM\n");
        printf("====================================================\n");
        printf("[?] Enter Authorization Passcode: ");
        if (!fgets(input, sizeof(input), stdin)) {
            return 1;
        }
        input[strcspn(input, "\r\n")] = 0;
    }

    size_t len = strlen(input);
    if (len != 36) {
        puts("[-] ACCESS DENIED: Invalid Key Length!");
        return 1;
    }

    init_vm_program(len);

    if (run_vm(input, len)) {
        puts("[+] ACCESS GRANTED // OBLIVION CORE UNLOCKED!");
        return 0;
    } else {
        puts("[-] ACCESS DENIED: Invalid Passcode!");
        return 1;
    }
}
