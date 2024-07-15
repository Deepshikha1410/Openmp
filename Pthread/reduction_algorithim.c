//modify progrma using reduction alogoithim 
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 30000
#define THREADS 16

pthread_mutex_t mutex;
long sum = 0;
int arr[N];

void *thread_sum(void* threadId) {
    long tid = (long)threadId;
    long start = tid * (N/THREADS);
    long end = (tid+1) * (N/THREADS);
    if(tid == THREADS-1) {
        end = N;
    }
    for(long i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        sum += arr[i];
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    for(int i =0; i < N; i++){
        arr[i] = i + i;
    }
    pthread_t* t;
    pthread_mutex_init(&mutex, NULL);
    t = malloc(sizeof(pthread_t)*THREADS);

    for (long i =0 ; i < THREADS; i++){
        pthread_create(&t[i],NULL, thread_sum,(void*)i);
    }
    for(long i =0; i<THREADS; i++) {
        pthread_join(t[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("Sum %ld\n",sum);
    free(t);
    return 0;
}