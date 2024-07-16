#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 100
#define THREADS_PER_SET 4

int total_sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* sum_function(void* arg) {
  int thread_sum = 10; // Simulate the sum of elements handled by a thread

  // Lock mutex to ensure thread-safe access to total_sum
  pthread_mutex_lock(&mutex);
  total_sum += thread_sum;
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];

  // Create 100 threads
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_create(&threads[i], NULL, sum_function, NULL);
  }

  // Wait for all threads to finish
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("Total sum: %d\n", total_sum);

  return 0;
}

