#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    pid_t pid;
    pid = fork();
    if(pid < 0) {
        printf("fork error\n");
        return 0;
    } else if(pid > 0) {
        printf("Parent process\n");
        int status = -1;
        pid_t pr = wait(&status);
        if(WIFEXITED(status)) {
            printf("The child process:%d exit normally.\n", pr);
            printf("the return code is %d\n", WEXITSTATUS(status));
        } else {
            printf("the child process %d exit abnormally\n", pr);
        } 
    } else if(pid == 0) {
            printf("done\n");
            exit(-1);
    }

    return 0;
}
