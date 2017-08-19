#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t ready;
pthread_mutex_t lock;
int x = 10;
int y = 20;


void* func1(void*) {
    printf("func1 start\n");
    pthread_mutex_lock(&lock);
    x = 20;
    y = 10;
    printf("x and y has changed\n");
    //pthread_mutex_unlock(&lock);
    while(x<y) {
        pthread_cond_wait(&ready, &lock);
    }
    pthread_mutex_unlock(&lock);
    sleep(3);
    printf("func1 end\n");
    return 0;
}


void* func2(void*) {
    printf("func2 start\n");
    pthread_mutex_lock(&lock);
    x = 20;
    y = 10;
    printf("x and y has changed by func2\n");
    pthread_mutex_unlock(&lock);
    if(x > y) {
        pthread_cond_signal(&ready);
    }
    printf("func2 end\n");
    return 0;
}


int main(int argc, char **argv) {
    pthread_t t1, t2;
    int ret;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&ready, NULL);

    ret = pthread_create(&t1, NULL, func1, NULL);
    if(ret < 0) {
        printf("create thread error\n");
        return ret;
    }

    
    sleep(2);
    ret = pthread_create(&t2, NULL, func2, NULL);
    if(ret < 0) {
        printf("create thread error\n");
        return ret;
    }

    ret = pthread_join(t1, NULL);
    if(ret < 0) {
        printf("join thread error\n");
        return ret;
    }
    ret = pthread_join(t2, NULL);
    if(ret < 0) {
        printf("join thread error\n");
        return ret;
    }
    return 0;
}
