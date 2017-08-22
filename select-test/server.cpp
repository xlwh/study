#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/wait.h>
#include <errno.h>

#define DEFAULT_PORT 6666


int main(int argc, char **argv) {
    int serverfd, acceptfd;
    struct sockaddr_in my_addr, their_addr;
    unsigned int sin_size, myport = 6666, lisnum = 10;

    if( (serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("create socket error\n");
        return -1;
    }

    printf("socket ok\n");
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(DEFAULT_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 0);

    if() {

    }

    return 0;
}
