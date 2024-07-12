#include<stdio.h>
#include<omp.h>
int main() {
	//Check if the main thred is in a parallel region
	if (omp_in_parallel()) {
		printf("Main thread is in a parallel region.\n");
	}
	else {
		printf("Main thread is NOT in a parallel region.\n");
	     }
	//parallel region
        #program omp parallel
	{
		//check if a worker thread is in a parallel region 
		if (omp_in_parallel()){
		       printf("Thread %d is in a parallel region.\n",omp_get_thread_num());
		}
		else {
		       printf("Thread %d is NOT in a parallel region.\n",omp_se
