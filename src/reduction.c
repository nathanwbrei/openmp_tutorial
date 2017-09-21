#include<stdio.h>
#include<omp.h>

void main(int argc, char** argv) {

  int buffer [10] = {1,5,2,8,4,1,0,7,3,7};
  int sum = 0;

  #pragma omp parallel for reduction(+:sum)
  for (int i=0; i<10; i++) {
    sum += buffer[i];
  }

  printf("Sum = %d\n", sum);
}
