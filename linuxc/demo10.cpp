#include <stdio.h>
#include <pthread.h>


class Hello {
public:
    static void* say(void* args) {
        printf("hello\n");
        pthread_exit((void*)1);
    }
};


int main(int argc, char **argv) {
    pthread_t tid;
    int iRet = pthread_create(&tid, NULL, Hello::say, NULL);
    if(iRet < 0) {
        printf("creat thread error\n");
        return iRet;
    }

    void* retval;
    iRet = pthread_join(tid, &retval);
    if(iRet < 0) {
        printf("pthread_join error\n");
        return iRet;
    }

    printf("return:%ld\n", (long*)retval);

    return 0;
}
