#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>


void * say(void*) {
    printf("sleep 5 seconds\n");
    sleep(5);
    printf("the thread done\n");
    return NULL;
}


int main(int argc, char **argv) {
    int ret;
    pthread_t tid;

    //创建一个新的线程，并绑定好线程的执行函数
    ret = pthread_create(&tid, NULL, say, NULL);
    if(ret < 0) {
        printf("create thread error:%s\n", strerror(ret));
        return ret;
    }
    
    //分离线程
    ret = pthread_detach(tid);
    if(ret) {
        printf("detach thread error:%s\n", strerror(ret));
        return ret;
    }

    //主线程在这里等待子线程的结束
    //但是在前面，这个线程已经被分离了
    //主线程不再能正确的获取到子线程的状态了
    ret = pthread_join(tid, NULL);
    if(ret) {
        printf("thread has been detach\n");
    }
    return 0;
}
