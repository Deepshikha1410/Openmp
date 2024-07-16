#include<stdio.h>
#include<omp.h>

int main() {
    int x = 10; 
    int y = 20;
#pragma omp parallel default(none) 
{
	
    int z = 30;
	x = omp_get_thread_num();
	printf("Thread %d: x = %d, y = %d\n",omp_get_thread_num(), x, y);
}

  return 0;

}

