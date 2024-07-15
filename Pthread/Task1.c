//Initialize an array of size N and assign each thread to print element which is equal to their threadId.
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define N 16

int arr[N];
 
void *hello(void *threadid) {
    long tid = (long)threadid;
    printf("Thread id %ld is printing %d\n",tid, arr[tid]);
    return NULL;
}
 int main(){
    pthread_t t[N];
    for(int i =0; i < N ;i++){
        arr[i] = i;
    }

     for(long i = 0; i < N; i++) {
      pthread_create(&t[i], NULL, hello, (void*)i);
    }
      for(long i = 0; i < N; i++) {
        pthread_join(t[i],NULL);
    }
 
    return 0;
}

