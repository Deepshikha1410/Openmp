#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 30000
#define CHUNK_SIZE 16

pthread_mutex_t mutex;
long sum = 0;
int arr[N];

void *thread_sum(void *arg) {
long threadId = (long)arg;
long start = threadId * CHUNK_SIZE;
long end = (threadId + 1) * CHUNK_SIZE;
if (end > N) {
 end = N;
}
long local_sum = 0;
for (long i = start; i < end; i++) {
 local_sum += arr[i];
}
 pthread_mutex_lock(&mutex);
sum += local_sum;
pthread_mutex_unlock(&mutex);
return NULL;
}

int main() {
for (int i = 0; i < N; i++) {
     arr[i] = i + i;
}
pthread_t *threads;
pthread_mutex_init(&mutex, NULL);
int num_threads = (N + CHUNK_SIZE - 1) / CHUNK_SIZE;
threads = malloc(sizeof(pthread_t) * num_threads);

for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, thread_sum, (void *)i);
}

for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
 }
pthread_mutex_destroy(&mutex);
printf("Sum: %ld\n", sum);
free(threads);
return 0;
 }