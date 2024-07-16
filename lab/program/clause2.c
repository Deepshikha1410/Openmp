#include<stdio.h>
#include<omp.h>

int main(){
	int array[]={1,2,3,4,5,6,7,8,9,10};
        int sum = 0;

       #pragma omp parallel for reduction(+:sum)
       for (int i = 0; i<10; ++i){
	    sum += array[i];
	   printf("Thread %d: sum = %d\n", thread_id, array[i]);
}
       printf("Sum: %d\n",sum);

       return 0;
}
