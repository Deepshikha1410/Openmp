#include<stdio.h>
#include<omp.h>

int main() {
    int shared_var = 5;//Shared variable

    #pragma omp parallel firstprivate(shared_var)
    {
	    shared_var += omp_get_thread_num(); //Each thread increments its private copy
	    printf("Thread %d: shared_var = %d\n",omp_get_thread_num(),shared_var);

    }

    printf("Outside parallel region, shared_var = %d\n",shared_var);

 return 0;

}
