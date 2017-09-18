#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  double balance = 10000.0;
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp atomic
      balance -= 50;
      #pragma omp barrier // End of Sept
      #pragma omp atomic
      balance *= 1.01;
      #pragma omp barrier // Start of Oct
    }
    #pragma omp section
    {
      #pragma omp atomic
      balance += 500;
      #pragma omp barrier // End of Sept
      #pragma omp barrier // Start of Oct
      #pragma omp atomic
      balance -= 50;
    }
  }
  printf("Balance = %.2f\n", balance);
}

