#include<stdio.h>
#include<omp.h>
int main(){
	int a=10;
#pragma omp parallel for 
	for(int i=0;i<10;i++){
		a++;
	 printf("a (inside the parallel region =%d\n",a);

	}
        printf("a (outside parallel region =%d\n",a);
	return 0;
}