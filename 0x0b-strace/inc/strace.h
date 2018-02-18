#ifndef _STRACE_H
#define  _STRACE_H

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <sys/user.h>
#include <sys/types.h>

#include "syscalls.h"

typedef int bool;
#define true 1
#define false 0

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifdef __amd64__
#define eax rax
#define orig_eax orig_rax
#else
#endif

bool is_machine_32(void);
unsigned long get_syscall_arg(struct user_regs_struct regs, int n);
#endif
