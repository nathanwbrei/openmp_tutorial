
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  int total = 0;
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      total = total + 1;
    }


    #pragma omp section
    {
      total = total + 2;
    }


  }
  printf("total=%d\n",total);
}

