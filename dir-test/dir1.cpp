#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "apue.h"

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *dirp;

    dp = opendir("/");

    if( dp == NULL) {
        printf("error opendir\n");
        return -1;
    }


    while((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    return 0;
}
