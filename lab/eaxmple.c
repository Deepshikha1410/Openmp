#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    int n = 100; // number of natural numbers to sum
    int partial_Sum, total_Sum;

    #pragma omp parallel private(partial_Sum) shared(total_Sum)
    {
        partial_Sum = 0;
        total_Sum = 0;

        #pragma omp for
        for(int i = 1; i <= n; i++){
            partial_Sum += i;
        }

        #pragma omp barrier

        #pragma omp critical
        {
            total_Sum += partial_Sum;
        }
    }

    printf("Sum of %d natural numbers: %d\n", n, total_Sum);

    return 0;
}
