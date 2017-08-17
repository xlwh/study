#include <apue.h>
#include <fcntl.h>

char buf1[] = "xxxxxsdadfads";
char buf2[] = "aaaaaaaaaaaaa";


int main() {
    int fd;

    //先调用create创建文件
    if((fd = creat("test.txt", FILE_MODE)) < 0) {
        printf("create file error\n");
    }

    if(write(fd, buf1, 10) != 10) {
        printf("write file error\n");
    }

    if(lseek(fd, 16384, SEEK_SET) == -1) {
        printf("seek error");
    }

    if(write(fd, buf2, 10) != 10) {
        printf("write buf2 error");
    }

    close(fd);

    return 0;
}
