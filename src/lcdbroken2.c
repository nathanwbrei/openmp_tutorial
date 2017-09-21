#include<stdio.h>
#include<omp.h>

void main(int argc, char** argv) {

  // BAD: Dependencies across threads
  int A[3][8] = {{1,5,2,8,4,1,0,7},
                 {5,6,8,1,3,6,8,9},
                 {1,2,6,3,1,7,3,3}};

  #pragma omp parallel for
  for (int i=1; i<3; i++) {
    for (int j=0; j<8; j++) {
      A[0][j] += A[i][j];
    }}
  for (int j=0; j<8; j++) {
    printf("%d ", A[0][j]);
  }
}
