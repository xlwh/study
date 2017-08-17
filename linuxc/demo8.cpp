#include <unistd.h>
#include <stdio.h>

int main() {
    int counter;

    alarm(2);

    for(counter=0; 1; counter++) {
        printf("count=%d\n", counter);
    }
    
    return 0;
}
