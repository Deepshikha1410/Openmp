#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 100

int main() {
    int data[ARRAY_SIZE];
    int max_value = data[0];
    int max_index = 0;

    // Initialize the array with some values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand() % 100;
    }

    #pragma omp parallel shared(data, max_value, max_index)
    {
        int local_max_value = data[0];
        int local_max_index = 0;

        #pragma omp for
        for (int i = 1; i < ARRAY_SIZE; i++) {
            if (data[i] > local_max_value) {
                local_max_value = data[i];
                local_max_index = i;
            }
        }

        #pragma omp critical
        {
            if (local_max_value > max_value) {
                max_value = local_max_value;
                max_index = local_max_index;
            }
        }

        #pragma omp barrier

        #pragma omp single
        {
            printf("Max value: %d, Max index: %d\n", max_value, max_index);
        }
    }

    return 0;
}
