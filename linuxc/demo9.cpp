#include <stdio.h>
#include <pthread.h>


void* sayhello(void* args) {
    printf("hello\n");
    pthread_exit((void*)1);
}


int main(int argc, char **argv) {
    pthread_t pid;

    int iRet = pthread_create(&pid, NULL, sayhello, NULL);
    
    if(iRet < 0) {
        printf("create thread error\n");
        return iRet;
    }

    void *retval;
    iRet = pthread_join(pid, &retval);
    if(iRet < 0) {
        printf("pthread_join error:", iRet);
        return iRet;
    }
    
    printf("return value:%ld\n", (long)retval);

    return 0;
}
