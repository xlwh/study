#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    pid_t pid = fork();
    int status;
    if(pid < 0) {
        printf("fork error\n");
    } else if(pid > 0) {
        printf("parent process\n");
        pid_t pr = wait(&status);
        printf("exit status:%d\n", status);
        printf("Parent process, I catched a child process with pid of %d\n", pr);
    } else if(pid == 0) {
        printf("Sub-process, PID:%u, PPID:%u\n", getpid(), getppid());
        exit(-1);
    }

    return 0;
}
