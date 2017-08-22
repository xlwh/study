#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>



int main(int argc, char **argv) {
   
    //初始化系统变量
    int fd;
    int ret,i;
    char c;
    fd_set readfd;
    struct timeval timeout;

    //打开键盘设备
    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if(fd < 0) {
        printf("open keyboard system error\n");
        return 0;
    }

    //轮询，等待事件的发生，一旦有读事件的发生，则开始进行数据的读取操作
    while(1) {
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        FD_ZERO(&readfd);
        FD_SET(fd, &readfd);
        ret = select(fd+1, &readfd, NULL, NULL, &timeout);
        if(FD_ISSET(fd, &readfd)) {
            i = read(fd, &c, 1);
            if(c == '\n') {
                continue;
            } else {
                printf("The input is:%c\n", c);
            }

            if(c == 'q') {
                break;
            }
        } else if(ret == 0) {
            printf("timeout, exit");
            return -1;
        }
    }

    return 0;
}
