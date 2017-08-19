#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    pid_t pid;
    pid = fork();
    if(pid < 0) {
        printf("fork error\n");
        exit(-1);
    }
    if(pid == 0) {
        //子进程退出，父亲=进程未退出
        //子进程将会成为一个僵尸进程
        printf("in child process,and exit\n");
    } else {
        printf("in parent process, sleep...\n");
        sleep(100);
        printf("after sleeping, and exit\n");
    }
    return 0;
}
