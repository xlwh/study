#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 0
#define OUTPUT 1

int main(int argc, char **argv) {
    int fd[2];
    pid_t pid;
    char buf[1024];
    int count;
    //创建管道
    pipe(fd);
    pid = fork();
    if(pid < 0) {
        printf("fork error\n");
    }
    //父进程，向写管道中写入数据
    if(pid > 0) {
        printf("in the parent process...\n");
        close(fd[INPUT]);
        write(fd[OUTPUT], "hello world", strlen("hello world, My name is zhanghongbin"));
        exit(0);
    }

    //子进程，读取父进程中的数据
    if(pid == 0) {
        printf("in the child process...\n");
        close(fd[OUTPUT]);
        count = read(fd[INPUT], buf, sizeof(buf));
        printf("%d bytes of data recved from parent process:%s\n", count, buf);
    }
    return 0;
}
