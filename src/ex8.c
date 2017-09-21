
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {


  int A[8] = {1,3,7,9,2,5,1,9};
  int sum = 0;
  int temp = 0;
  #pragma omp parallel sections shared(sum) firstprivate(temp)
  {
    #pragma omp section
    {
      for (int i = 0; i < 4; i++) temp += A[i];
      printf("temp=%d\n",temp);
      #pragma omp critical (c1)  // For code blocks
      sum += temp;
    }
    #pragma omp section
    {
      for (int i = 4; i < 8; i++) temp += A[i];
      printf("  temp=%d\n",temp);
      #pragma omp atomic   // For ops like +=
      sum += temp;
    }
  }
  printf("sum=%d\n", sum);
}

