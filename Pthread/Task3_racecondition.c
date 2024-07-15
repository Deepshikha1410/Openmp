#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 500000

long sum = 0;

void *thread_sum(void* threadId) {
    long tid = (long)threadId;
    sum +=tid;
    return NULL;
}

int main() {
    pthread_t* t;
    t = malloc(sizeof(pthread_t)*N);

    for (long i =0 ; i < N; i++){
        pthread_create(&t[i],NULL, thread_sum,(void*)i);
}
    for(long i =0; i<N; i++) {
        pthread_join(t[i],NULL);
    }
    printf("Sum %ld\n",sum + N);
    return 0;
}
    
