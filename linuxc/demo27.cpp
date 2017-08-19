#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    pid_t pid, pr;
    pid = fork();
    if(pid < 0) {
        printf("error fork\n");
        exit(-1);
    }

    if(pid > 0) {
        do{
            pr = waitpid(pid, NULL, WNOHANG);
            if(pr == 0) {
                printf("No child\n");
                sleep(10);
            }
        }while(pr == 0);

        if(pr == pid) {
                printf("success get process\n");
        } else {
                printf("error\n");
        }
    }

    if(pid == 0) {
        printf("sub process will sleep\n");
        sleep(10);
        exit(0);
    }

    return 0;
}
