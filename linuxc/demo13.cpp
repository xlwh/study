#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


//pthread_mutex_t mutex_x = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_x;
int total = 20;

void* sell(void*) {
    for(int i=0;i<20; i++) {
       pthread_mutex_lock(&mutex_x);
        if(total > 0) {
            sleep(5);
            printf("selled:%d\n", 20-total);
            total--;
        }
       pthread_mutex_unlock(&mutex_x);
    }
    return 0;
}


int main(int argc, char **argv) {
    int ret;
    pthread_t tids[4];

    //初始化锁
    pthread_mutex_init(&mutex_x, NULL);

    for(int i=0; i<4; i++) {
        ret = pthread_create(&tids[i], NULL, sell, NULL);
        if(ret < 0) {
            printf("create thread error\n");
            return ret;
        }
    }

    sleep(30);
    void *retval;
    for(int i=0; i<4; i++) {
        ret = pthread_join(tids[i], &retval);
        if(ret) {
            printf("tid=%d, join error, ret=%d\n", tids[i], ret);
            return ret;
        }
    }

    return 0;
}
