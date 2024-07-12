#include <stdio.h>
#include <omp.h>
#define num 100
int main() {
	 int number[num];
	 int sum = 0;

#pragma omp parallel for
	 for(int i = 0; i<num; i++){
		 number[i] = i+1;
	 }
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <=num ; i++) {
        sum += i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
