
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  int a = 0;
  int b = 0;
  #pragma omp parallel sections
  {
    #pragma omp section
    a = 1;

    #pragma omp section
    b = a;
  }
  printf("b = %d\n", b);
}
