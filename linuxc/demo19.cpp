#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define CUSTOM_NUM 10



sem_t sem;
int ret;

void* service(void* id) {
    int custom_id = *((int*)id);
    if(sem_wait(&sem) == 0) {
        usleep(100);
        printf("customer %d received...\n");
        sem_post(&sem);
    }

}


int main(int argc, char **argv) {
    sem_init(&sem, 0, 2);
    pthread_t tids[CUSTOM_NUM];
    for(int i = 0; i < CUSTOM_NUM; i++) {
        ret = pthread_create(&tids[i], NULL, service, (void*)&i);
        if(ret < 0) {
            printf("Create thread error\n");
        } else {
            printf("Customer %d arrived\n", i);
        }
        usleep(10);
    }

    for(int i = 0; i< CUSTOM_NUM; i++) {
        ret = pthread_join(tids[i], NULL);
        if(ret < 0) {
            printf("join thread error\n");
            return ret;
        }
    }
    return 0;
}
