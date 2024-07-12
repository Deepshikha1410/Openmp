#include <omp.h>
#include <stdio.h>
int main() {
    int sum = 0;
    int arr[100];

   

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100; i++) {
        sum += arr[i];
 	printf("The sum of numbers from 1 to 100 is: %d\n", sum);
    }


    return 0;
}
