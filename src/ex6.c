
#include<stdio.h>
#include<omp.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char** argv) {

  int i = 22;
  int t = 22;
  printf("Before: i=%d,t=%d\n",i,t);
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      t = omp_get_thread_num();
      for (i = 0; i < 4; i++) {
        sleep(rand() % 4);
        printf("i=%d, t=%d\n",i,t);
      }
    }
    #pragma omp section
    {
      t = omp_get_thread_num();
      for (i = 4; i < 8; i++) {
        sleep(rand() % 4);
        printf("  i=%d,t=%d\n",i,t);
      }
    }
  }
  printf("After: i=%d,t=%d\n",i,t);
}

