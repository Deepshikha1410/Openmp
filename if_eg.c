#include <stdio.h>
#include <omp.h>

int main(){

/*	//check if the main thread is in a parallel region
	
       	if (omp_in_parallel()){
		printf("Main thread is in a parallel region.\n");
	}
	else {
		printf("Main thread is not in a parallel region.\n");
	}

	//Parallel region */
	int n = 50;
	#pragma omp parallel if(n>100)
	{
		printf("The thread %d is executing inside parallel region\n", omp_get_thread_num());
	}
	
	return 0;
}
