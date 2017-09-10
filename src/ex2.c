
#include<stdio.h>
#include<unistd.h>
#include<omp.h>

int main(int argc, char** argv) {

  #pragma omp parallel sections
  {
    #pragma omp section
    {
      int t = omp_get_thread_num();
      for (int i=0; i<10; i++) {
        sleep(2);
        printf("Section 1 currently at %d\n",i);
      }
    }
    #pragma omp section
    {
      int t2 = omp_get_thread_num();
      for (int i=0; i<10; i++) {
        sleep(1);
        printf("Section 2 currently at %d\n",i);
      }
    }
  }
}
