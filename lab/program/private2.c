#include<stdio.h>
#include<omp.h>

int main (){
	int x = 10;

	#pragma omp parallel private(x)
	{
		x = omp_get_thread_num();
		printf("Thread %d has private x = %d,address=%p\n", omp_get_thread_num(),x,&x);
	}

	printf("Value of x outside parallel region = %d",x);
	return 0;
}
