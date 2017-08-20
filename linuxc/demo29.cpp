#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define P_FIFO "/tmp/p_fifo"

int main(int argc, char **argv) {
    char cache[100];
    int fd;
    memset(cache, 0, sizeof(cache));
    //判断管道文件是否存在
    if(access(P_FIFO, F_OK) == 0) {
        printf("file exist, will remove\n");
        execlp("rm", "-f", P_FIFO, NULL);
    }

    //创建命名管道
    if(mkfifo(P_FIFO, 0777) < 0) {
        printf("make fifo error\n");
    }

    fd = open(P_FIFO, O_RDONLY|O_NONBLOCK);
    while(1) {
        memset(cache, 0, sizeof(cache));
        if(read(fd, cache, 100) == 0) {
            printf("no data\n");
        } else {
            printf("get data:%s\n", cache);
        }
        sleep(2);
    }
    close(fd);
    return 0;
}
