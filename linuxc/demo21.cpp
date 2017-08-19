#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int global =1;

int main(int argc, char **argv) {
    pid_t pid;
    int stack = 1;
    int *heap;
    heap = (int*)malloc(sizeof(int));
    *heap = 1;
    pid = fork();
    if(pid < 0) {
        printf("fail to fork\n");
        exit(-1);
    }

    if(pid == 0) {
        global++;
        stack++;
        (*heap)++;

        printf("In sub-process, global is:%d, stack:%d, heap:%d\n", global, stack, *heap);
        exit(0);
    } else {
        sleep(2);
        printf("In parent-process, global is:%d, stack:%d, heap:%d\n", global, stack, *heap);
    }

    return 0;
}
