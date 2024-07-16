#include<stdio.h>
#include<omp.h>

int main() {
    int x = 5;//shared variable 
    int y = 7;//shared variable

#pragma omp parallel default(shared) private(x,y)
{
	printf("initial value of x = %d, y = %d \n", x, y);
	x = omp_get_thread_num();//Private copy of x for each thread
	y += x; //Private copy of y for each thread, each thread increments its private copy
	printf("Thread %d: x = %d, y = %d\n",omp_get_thread_num(), x, y);
}

  printf("outside parallel region : value of x = %d, y = %d \n",x, y);

  return 0;

}

