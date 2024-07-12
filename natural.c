#include <stdio.h>
#include <omp.h>

int main() {
    int N = 100; // Change this value to calculate the sum for a different N
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }

    printf("Sum of the first %d natural numbers: %d\n", N, sum);

    return 0;
}

