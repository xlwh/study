#include <stdio.h>
#include <unistd.h>
#include "apue.h"


int main(int argc, char **argv) {
    if(lseek(STDIN_FILENO, 0, SEEK_CUR)) {
        printf("cannot seek\n");
    } else {
        printf("seek ok\n");
    }
    return 0;
}
