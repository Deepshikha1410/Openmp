#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<pthread.h>

#define N 999999999
#define THREAD_COUNT 4

double total_area = 0.0;
double dx;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *calculate_area(void *arg) {
    long threadId = *(long *)arg;
    long start = threadId * (N / THREAD_COUNT);
    long end = (threadId + 1) * (N / THREAD_COUNT);
    double area = 0.0;
    double x, y;
    for (long i = start; i < end; i++) {
        x = i * dx;
        y = sqrt(1 - x * x);
        area += y * dx;
    }

    pthread_mutex_lock(&mutex);
    total_area += area;
    pthread_mutex_unlock(&mutex);

    free(arg); 
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    long *threadIds[THREAD_COUNT];
    struct timeval start_time, stop_time;
    dx = 1.0 / N;

    gettimeofday(&start_time, NULL);

    for (int i = 0; i < THREAD_COUNT; i++) {
        threadIds[i] = malloc(sizeof(long)); 
        *threadIds[i] = i; 
        pthread_create(&threads[i], NULL, calculate_area, threadIds[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&stop_time, NULL);
    double exe_time = (stop_time.tv_sec + (stop_time.tv_usec / 1000000.0)) - (start_time.tv_sec + (start_time.tv_usec / 1000000.0));

    double pi = 4.0 * total_area;
    printf("\n Value of pi is = %.16lf\n Execution time is = %lf seconds\n", pi, exe_time);

    return 0;
}