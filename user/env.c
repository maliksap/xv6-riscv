#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"



void env(int size, int interval, char* env_name) {
    int result = 1;
    int loop_size = 1000;
    int n_forks = 2;
    int pid;
    for (int i = 0; i < n_forks; i++) {
        pid = fork();
    }

    for (int i = 0; i < loop_size; i++) {
        //  int loopSizeDevided = loop_size / 10e0;
        // if (i % loopSizeDevided == 0) {
        	if (pid == 0) {
        		printf("%s %d/%d completed.\n", env_name, i, loop_size);
        	} else {
        		printf(" ");
        	}
        //  }
        if (i % interval == 0) {
            result = result * size;
        }
    }
    printf("\n");
}

void env_large() {
    env(10e6, 10e6, "env_large");
}

void env_freq() {
    env(10e1, 10e1, "env_freq");
}

int main(int argc, char *argv[])
{
    env_large();
    env_freq();
    print_stat();
    exit(0);
    return 0;
}