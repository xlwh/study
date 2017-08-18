#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutex;
int total = 200;

void* sell_ticket(void*){
    int ret;
    for(int i=0; i<= 200; i++) {
        //获取锁
        ret = pthread_mutex_trylock(&mutex);
        if(ret == EBUSY) {
            printf("the ticket loacked\n");
        } else if(ret == 0) {
            if(total >0) {
                printf("selled:%d\n", 200-total);
                total--;
            }
            pthread_mutex_unlock(&mutex);
        }
        sleep(3);
    }
    return 0;
}

int main(int argc, char **argv) {
    pthread_t tids[5];
    int ret;
    
    pthread_mutex_init(&mutex, NULL);

    for(int i=0; i < 5; i++) {
        ret = pthread_create(&tids[i], NULL, sell_ticket, NULL);
        if(ret < 0) {
            printf("create thread error\n");
            return ret;
        }
    }

    //join
    for(int i=0; i < 5; i++) {
        ret = pthread_join(tids[i], NULL);
        if(ret < 0) {
            printf("join error\n");
        }
    }

    return 0;
}
