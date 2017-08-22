#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 4096


int main(int argc, char **argv) {
    int socketfd, n;
    char recvline[MAXSIZE], sendline[MAXSIZE];
    struct sockaddr_in serveraddr;

    if( argc != 2 ) {
        printf("usage: ./client <ipaddress>\n");
        return 0;
    }

    if( (socketfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ) {
        printf("create socket error:%s(errno:%d)", strerror(errno), errno);
        return -1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(6666);

    if( inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0 ) {
        printf("inet_pton error for %s\n", argv[1]);
        return 0;
    }

    if(connect(socketfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("conn server error\n");
        return -1;
    }

    printf("send msg to server:\n");
    fgets(sendline, 4096, stdin);

    if(send(socketfd, sendline, strlen(sendline), 0) < 0) {
        printf("send error\n");
    }

    close(socketfd);

    return 0;
}
