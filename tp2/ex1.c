#include <cstdio>
#include <unistd.h>
#include "omp.h"

int main(int argc, char **argv)
{
  printf("avant parallel\n");
#pragma omp parallel num_threads(10)
  {
    int thid = omp_get_thread_num();
    int nthreads = omp_get_num_threads();
    printf("hello from %d out of %d\n", thid, nthreads);
  }
  return 0;
}
