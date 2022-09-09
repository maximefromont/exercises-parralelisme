#include <cstdio>
#include <unistd.h>
#include "omp.h"

int main(int argc, char **argv)
{

  int N = 5;
  float array[N];
  float somme = 0.f;
  
  #pragma omp parallel 
  {

    #pragma opm for
    for(int i = 0; i < N; i++)
    {
      array[i] = i;  
    }

    #pragma opm for
    for(int i = 0; i < N; i++)
    {
      somme = somme + array[i];
    }

  }
  
  printf("La somme est de %f\n", somme);
  printf("La somme est censé être %d\n", ((N-1)*N)/2);

  return 0;
}
