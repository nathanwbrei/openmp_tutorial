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
      balance -= 50;   // Munich withdrawal

      #pragma omp atomic
      balance *= 1.01; // Interest
    }
    #pragma omp section
    {
      #pragma omp atomic
      balance += 500;  // HiWi income

      #pragma omp atomic
      balance -= 50;   // Bozen withdrawal
    }
  }
  printf("Balance = %.2f\n", balance);
}

