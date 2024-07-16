#include<stdio.h>
#include<omp.h>
int main(){
#pragma omp parallel sections
{
#pragma omp section
{
	printf("This is section1,executed by thread %d\n",omp_get_thread_num());
}

#pragma omp section 
{
	printf("This is section2,executed by thread %d\n",omp_get_thread_num());}
}
return 0;
}
