#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#define N 100
int main(){
	int a[N];
#pragma omp parallel num_threads(N)
	{
		int i= omp_get_thread_num();
		a[i]=rand() % 1000 + 1;
#pragma omp barrier
#pragma omp single
		{
			for (int j=0;j<N;j++){
				if(a[j] > maximum_by_single){

