#include <apue.h>

#define MAXSIZE 4096

int main() {
   int n;
   char buf[MAXSIZE];

   
   while(( n = read(STDIN_FILENO, buf, MAXSIZE) ) > 0) {
       if(write(STDOUT_FILENO, buf, n) != n) {
            printf("write error");
       }
   }

    return 0;
}
