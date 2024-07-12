#include<omp.h>
#include <stdio.h> 

int main() 
{ 

    
	int arr[] = { 1,20,33,44,99,100,999,458}; 

	
	int n = sizeof(arr) / sizeof(arr[0]); 


	int res = arr[0];
#pragma omp parallel
	
#pragma omp master
	if(omp_get_thread_num()==0){
	printf("Thread id:%d\n",omp_get_thread_num());
	for (int i = 0; i < n; i++) { 
		if (res < arr[i]) 
			res = arr[i]; 
	} 
        }
	printf("Array Elements: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	
	}
		
	printf("\n"); 

	printf("The maximum value of the array is: %d", res); 

	return 0; 
}

