
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  int A[16];

  #pragma omp parallel for schedule(static,2)
  for (int i = 0; i < 16; i++)
  {
      A[i] = omp_get_thread_num();
  }
  for (int i=0; i < 16; i++)
  {
    printf("A[%d] got thread %d\n", i, A[i]);
  }
}

