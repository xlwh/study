#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

pthread_mutex_t lock;
pthread_cond_t cond;

void* travel(void* name) {
    cout << "Travel:" << (char *)name << " need a taxi" << endl;
    pthread_mutex_lock(&lock);
    //等待条件的产生
    pthread_cond_wait(&cond, &lock);
    pthread_mutex_unlock(&lock);
    cout << "Travel" << (char *)name << " now got a taxi" << endl;

    pthread_exit((void*)0);
}


void* taxi(void* name) {
    cout << "Taxi:" << (char*)name <<" arrives" << endl;
    pthread_cond_signal(&cond);
    pthread_exit((void*)0);
}


int main(int argc, char **argv) {
    pthread_t tids[3];
    int ret;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    //创建司机jack到达线程
    ret = pthread_create(&tids[0], NULL, taxi, (void*)"Jack");
    if(ret < 0) {
        cout << "create thread jack taxi error" << endl;
        return ret;
    }

    //wait
    sleep(2);
    
    //创建乘客susan到达线程
    ret = pthread_create(&tids[1], NULL, travel, (void*)("susan"));
    if(ret < 0) {
        cout << "create travel susan thread error" << endl;
        return ret;
    }

    //wait
    sleep(2);
    ret = pthread_create(&tids[2], NULL, taxi, (void*)("Mike"));
    if(ret < 0) {
        cout << "create taxi Mike error" << endl;
        return ret;
    }

    //join
    for(int i = 0; i < 3; i++) {
        ret = pthread_join(tids[i], NULL);
        if(ret < 0) {
            cout << "join thread error" << endl;
            return ret;
        }
    }

    return 0;
}
