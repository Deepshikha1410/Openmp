#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000 

int main() {
 
    int **A, **B
    / Initialize matrices
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
    A[i][j] = i * SIZE + j;
    B[i][j] = i * SIZE + j;
    }
    }

    double start_time, end_time;

    // Start time measurement
    start_time = omp_get_wtime();

    // Parallel matrix addition using OpenMP
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
    C[i][j] = A[i][j] + B[i][j];
    }
    }

    // End time measurement
    end_time = omp_get_wtime();

// Print the first few elements of the resulting matrix (optional)
printf("Resulting matrix (first few elements):\n");
for (int i = 0; i < 5; i++) {
for (int j = 0; j < 5; j++) {
printf("%d ", C[i][j]);
}
printf("\n");
}

// Print execution time
printf("Time taken by CPU: %.6lf seconds\n", end_time - start_time);

return 0;
}

