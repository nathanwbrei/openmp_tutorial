
#include<stdio.h>
#include<omp.h>
int main(int argc, char** argv) {

  store 0 -> (total)
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      load (total) -> a
      add 1, a -> b
      store b -> (total)
    }
    #pragma omp section
    {
      load (total) -> c
      add 2, c -> d
      store d -> (total)
    }
  }
  load (total) -> a
  call printf
}

