
#include<stdio.h>
#include<omp.h>

int main(int argc, char** argv) {

  int balance = 0;
  omp_set_num_threads(20);
  for (int i = 0; i< 1000; i++) {
    balance = 0;

    #pragma omp parallel
    balance += omp_get_thread_num();

    printf("Balance at end is: %d\n", balance);
  }
}
