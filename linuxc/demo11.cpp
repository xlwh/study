#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


void* say(void*) {
    printf("Hello\n");
    return NULL;
}



int main(int argc, char **argv) {
    int iRet;
    pthread_t tid;
    pthread_attr_t attr;

    iRet = pthread_attr_init(&attr);
    if(iRet) {
        printf("cannot set pthread attr:%s\n", strerror(iRet));
        return iRet;
    }

    iRet = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(iRet) {
        printf("cannot set pthread datachstate:%s\n", strerror(iRet));
        return iRet;
    }
    iRet = pthread_create(&tid, &attr, say, NULL);
    if(iRet) {
        printf("Create thread error:%s\n", strerror(iRet));
        return iRet;
    }
    iRet = pthread_join(tid, NULL);
    if(iRet) {
        printf("thread has been detached\n");
        return iRet;
    }

    return 0;
}
