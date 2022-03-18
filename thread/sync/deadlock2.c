//
// Created by qwskyz on 2022/3/14.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t t1;
pthread_mutex_t t2;


void* workA(void * arg) {
    printf("Thread1 start to run\n");
    pthread_mutex_lock(&t1);
    printf("Thread1 has locked t1\n");
    sleep(3000);
    pthread_mutex_lock(&t2);
    printf("Thread1 has locked t2\n");

    pthread_mutex_unlock(&t2);
    pthread_mutex_unlock(&t1);
}

void* workB(void * arg) {
    printf("Thread2 start to run\n");
    pthread_mutex_lock(&t2);
    printf("Thread1 has locked t2\n");
    sleep(3000);
    pthread_mutex_lock(&t1);
    printf("Thread2 has locked t1\n");

    pthread_mutex_unlock(&t1);
    pthread_mutex_unlock(&t2);
}

int main() {
    // init mutx lock
    pthread_mutex_init(&t1, NULL);
    pthread_mutex_init(&t2, NULL);

    pthread_t tid1;
    pthread_t tid2;

    // create threads
    pthread_create(&tid1, NULL, workA, NULL);
    pthread_create(&tid2, NULL, workB, NULL);

    // 回收子线程资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // 释放互斥量资源
    pthread_mutex_destroy(&t1);
    pthread_mutex_destroy(&t2);
    return 0;
}