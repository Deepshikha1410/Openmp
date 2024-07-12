#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define TOTAL_THREADS 100

int a[TOTAL_THREADS]; // Array to store thread sums
int chunkSize; // Size of each chunk

void* computeSum(void* arg) {
    int threadId = *(int*)arg;
    int start = threadId * chunkSize;
    int end = (threadId + 1) * chunkSize;

    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += a[i];
    }

    a[threadId] = sum; // Store the sum for this thread

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    // Initialize the array with thread IDs (0, 1, 2, 3, ..., 99)
    for (int i = 0; i < TOTAL_THREADS; ++i) {
        a[i] = i;
    }

    chunkSize = TOTAL_THREADS / NUM_THREADS;

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, computeSum, &threadIds[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Combine partial sums
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; ++i) {
        totalSum += a[i];
    }

    printf("Total sum of 100 threads divided into 4 sets: %d\n", totalSum);

    return 0;
}

