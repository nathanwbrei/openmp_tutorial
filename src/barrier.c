#include<stdio.h>
#include<omp.h>

void main(int argc, char** argv) {
  #pragma omp parallel sections
  {
    #pragma omp section
    printf("Thread 0 did some work.\n");

    #pragma omp section
    printf("Thread 1 did some work.\n");
  }
  printf("Threads rejoin\n");

  #pragma omp parallel sections
  {
    #pragma omp section
    printf("Thread 0 after barrier.\n");

    #pragma omp section
    printf("Thread 1 after barrier.\n");
  }
}
