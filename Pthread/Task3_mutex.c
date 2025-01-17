#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 20000

pthread_mutex_t mutex;
long sum = 0;

void *thread_sum(void* threadId) {
    long tid = (long)threadId;
    pthread_mutex_lock(&mutex);
    sum +=tid;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t* t;
    pthread_mutex_init(&mutex, NULL);
    t = malloc(sizeof(pthread_t)*N);

    for (long i =0 ; i < N; i++){
        pthread_create(&t[i],NULL, thread_sum,(void*)i);
}
    for(long i =0; i<N; i++) {
        pthread_join(t[i],NULL);
    pthread_mutex_destroy(&mutex);
    }
    printf("Sum %ld\n",sum + N);
    free(t);
    return 0;
}
    
