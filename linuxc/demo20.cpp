#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv) {
    pid_t pid;
    pid = fork();
    if(pid < 0) {
        printf("create subprocess error\n");
        exit(-1);
    } else if( pid == 0 ) {
        printf("This is a sub process\n");
    } else {
        printf("this is a main process\n");
        sleep(10);
    }

    return 0;
}
