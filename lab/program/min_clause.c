#include<stdio.h>
#include<omp.h>

int main(){
	int array[]={1,2,3,4,5,6,7,8,9,10};
        int min =array[0];

       #pragma omp parallel for reduction(min:min) num_threads(8)
       for (int i = 0; i<10; ++i){
       int thread_id = omp_get_thread_num();
       if (array[i]>min){
	    min = array[i];
     }	    
	   printf("Thread %d:Iteration %d,sum = %d\n", thread_id, min,i);
}
       printf("min: %d\n",min);

       return 0;
}
