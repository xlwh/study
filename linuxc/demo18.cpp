#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADNUM 5
pthread_rwlock_t rwlock;

void* readers(void* args) {
    pthread_rwlock_rdlock(&rwlock);
    printf("got lock:%ld\n", (long)args);
    pthread_rwlock_unlock(&rwlock);
    sleep(5);
    pthread_exit((void*)0);
}

void* writers(void* args) {
    pthread_rwlock_wrlock(&rwlock);
    printf("got a write lock:%ld\n", (long)args);
    sleep(5);
    pthread_rwlock_unlock(&rwlock);
    pthread_exit((void*)0);
}

int main(int argc, char **argv) {
    int ret, i;
    pthread_t wthread, rthread;
    pthread_attr_t attr;
    int readCount = 1;
    int writeCount = 1;
    
    ret = pthread_rwlock_init(&rwlock, NULL);
    if(ret < 0) {
        printf("init rwlock error\n");
        return ret;
    }
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for(i = 0; i< THREADNUM; i++) {
        if(i % 3) {
            pthread_create(&rthread, &attr, readers, (void*)readCount);
            printf("create reader%d\n", readCount++);
        } else {
            pthread_create(&wthread, &attr, writers, (void*)writeCount);
            printf("create writer:%d\n", writeCount++);
        }
    }
    sleep(20);
    return 0;
}

