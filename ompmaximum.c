#include<stdio.h>
#include<omp.h>
#define N 100

int main(){
	int rand(N);
	int maxvalue =rand(0);
	

#pragma omp parallel num_threads(N)
{
	int i = omp_get_thread_num();

#pragma omp barrier
#pragma omp master
{
  printf("thread id: %d\n",omp_get_thread_num());
	    for(int j = 0; j < N; j++) {
		    ;
		 }
}
}

printf("max = %d\n",max);
return 0;
}       
