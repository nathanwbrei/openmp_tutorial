
#include<stdio.h>
#include<omp.h>

int main(int argc, char** argv) {
  printf("About to fork...\n");

  #pragma omp parallel num_threads(3)
  {
    printf("Hello from thread %d of %d\n",
           omp_get_thread_num(),
           omp_get_num_threads());
  }
  printf("...Rejoined.\n");
}
