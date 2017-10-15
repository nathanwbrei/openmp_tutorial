#include<stdio.h>
#include<omp.h>

void main(int argc, char** argv) {
  #pragma omp parallel 
  {
    #pragma omp sections 
    {
      #pragma omp section
      printf("Thread 0 did some work.\n");

      #pragma omp section
      printf("Thread 1 did some work.\n");
    } // Implicit barrier
    #pragma omp sections nowait
    {
      #pragma omp section
      printf("Thread 0 after barrier.\n");

      #pragma omp section
      printf("Thread 1 after barrier.\n");
    } // No barrier

    // All threads do some work 
    #pragma omp barrier
    // All threads do some work
  } // Implicit barrier
}
