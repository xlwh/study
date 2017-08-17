#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("uid is:%d, group id is:%d\n", getuid(), getgid());
    return 0;
}
