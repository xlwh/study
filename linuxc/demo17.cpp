#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;


pthread_cond_t taxiCond;
pthread_mutex_t taxiMutex;

int waitCount = 0;

void* travel_arrive(void* name) {
    cout << "Traveler:" << (char*)name << " need a taxi" << endl;
    pthread_mutex_lock(&taxiMutex);
    pthread_cond_wait(&taxiCond, &taxiMutex);
    waitCount++;
    pthread_mutex_unlock(&taxiMutex);
    cout << "Travel:" << (char*)name << " now got a taxi" << endl;
   // waitCount --;
    pthread_exit((void*)0);
}

void* taxi_arrive(void* name) {
    cout << "Taxi:" << (char*) name << " arrived" << endl;
    //一直等待，只要站台上有乘客，就立马通知
    //避免互相等待
    while(1) {
        pthread_mutex_lock(&taxiMutex);
        if(waitCount > 0) {
            pthread_cond_signal(&taxiCond);
            pthread_mutex_unlock(&taxiMutex);
            break;
        }
        pthread_mutex_unlock(&taxiMutex);
    }
    pthread_exit((void*)0);
}


int main(int argc, char **argv) {
    pthread_t tids[3];
    int ret;
    ret = pthread_create(&tids[0], NULL, taxi_arrive, (void*)("Jack"));
    if(ret < 0) {
        cout << "create taxi thread error" << endl;
        return ret;
    }
    //wait
    cout << "taxi wait" << endl;
    sleep(2);

    ret = pthread_create(&tids[1], NULL, travel_arrive, (void*)("Susan"));
    if(ret < 0) {
        cout << "create treveler thred error" << endl;
        return ret;
    }

    cout << "Traveler wait" << endl;
    sleep(2);

    ret = pthread_create(&tids[2], NULL, taxi_arrive, (void*)("Mike"));
    if(ret < 0) {
        cout << "Create taxi thread error" << endl;
        return  ret;
    }

    for(int i = 0; i < 3; i++) {
        ret = pthread_join(tids[i], NULL);
        if(ret < 0) {
            cout << "join thread error" << endl;
            return ret;
        }
    }
    return 0;
}
