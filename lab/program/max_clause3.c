#include<stdio.h>
#include<omp.h>

int main(){
	int array[]={1,2,3,4,5,6,7,8,9,10};
        int max =array[0];

       #pragma omp parallel for reduction(max:max) num_threads(4)
       for (int i = 0; i<10; ++i){
       int thread_id = omp_get_thread_num();
       if (array[i]>max){
	    max = array[i];
     }	    
	   printf("Thread %d:Iteration %d,sum = %d\n", thread_id, max,i);
}
       printf("max: %d\n",max);

       return 0;
}
