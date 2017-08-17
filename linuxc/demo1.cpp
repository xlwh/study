#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <signal.h>

#define MAXSIZE 4096

static void sig_int(int);

int main(int argc, char **argv) {
    char buf[MAXSIZE];
    pid_t pid;
    int status;

    //使用一个while循环一直等待，从标准输入中读取命令
    while(fgets(buf, MAXSIZE, stdin) != NULL) {
        //删除换行符
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
        
        if(signal(SIGINT, sig_int) == SIG_ERR) {
            printf("process signal error\n");
        }

        //fork一个子进程执行输入的命令
        if((pid = fork()) < 0) {
            printf("fork subprocess error\n");
            exit(127);
        }

        //执行命令
        if(pid == 0) {
            execlp(buf, buf, (char *)0);
        }

        if((pid = waitpid(pid, &status, 0)) < 0) {
            printf("wait pid error\n");
        }
    }

    return 0;
}

void sig_int(int signo) {
    printf("signal is:%d\n", signo);
    if(signo == 2) {
        printf("bye bye\n");
        exit(0);
    }
}
