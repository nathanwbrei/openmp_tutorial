
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  #pragma omp parallel sections
  {
    #pragma omp section
    {
      int t = omp_get_thread_num();
      for (int i=0; i<4; i++)
        printf("Thread %d, iter %d\n",t,i);
    }
    #pragma omp section
    {
      int t = omp_get_thread_num();
      for (int i=0; i<4; i++)
        printf("  Thread %d, iter %d\n",t,i);
    }}}
