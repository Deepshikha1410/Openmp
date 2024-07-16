#include<stdio.h>
#include<omp.h>

int main (){
	int x = 10;

	#pragma omp parallel private(x)
	{
		printf("Value of x inside parallel region = %d \n", x);
		x = omp_get_thread_num();
		printf("Thread %d has private x = %d\n", omp_get_thread_num(),x);
	}

	printf("Value of x outside parallel region = %d",x);
	return 0;
}
