#include <iostream>
#include "omp.h"

int main(int argc, char **argv)
{

  int N = 10;
  int array[N];
  int somme = 0;

  for(int i = 0; i < N; i++)
  {
      array[i] = i;  
  }
  
  #pragma omp parallel 
  {

    #pragma opm sections reduction(+ : somme)
    {

      #pragma opm section
      {
        for(int i = 0; i < N/4; i++)
        {
          somme = somme + array[i];
        }
      }
     #pragma opm section
      {
        for(int i = N/4; i < N/2; i++)
        {
          somme = somme + array[i];
        }
      }
     #pragma opm section
      {
        for(int i = N/2; i < 3*(N/4); i++)
        {
          somme = somme + array[i];
        }
      }
     #pragma opm section
      {
        for(int i = 3*(N/4); i < N; i++)
        {
          somme = somme + array[i];
        }
      }
    }
  }
  
  printf("La somme est de %d\n", somme);
  printf("La somme est censé être %d\n", ((N-1)*N)/2);

  return 0;
}
