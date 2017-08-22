#include "apue.h"

int main(int argc, char **argv) {
    int c;
    while((c = getc(stdin)) != EOF) {
        if(putc(c, stdout) == EOF) {
            printf("output error\n");
        }

    }
}
