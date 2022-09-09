#include <iostream>
#include "omp.h"

int main()
{
	int N = 10000;
	double A[N];
	double somme = 0;
	#pragma omp parallel
	{
		#pragma omp sections 
		{
			#pragma omp section
			{
				for (int i=0; i<N/4; i++)
				{
					A[i] =  i;
				}
				double localsomme = 0;
				for (int i=0; i<N/4; i++)
				{
					localsomme += A[i];
				}
				#pragma omp atomic
				somme += localsomme;
			}
			#pragma omp section
			{
				for (int i=N/4; i<2*N/4; i++)
				{
					A[i] =  i;
				}
				double localsomme = 0;
				for (int i=N/4; i<2*N/4; i++)
				{
					localsomme += A[i];
				}
				#pragma omp atomic
				somme += localsomme;
			}
			#pragma omp section
			{
				for (int i=2*N/4; i<3*N/4; i++)
				{
					A[i] =  i;
				}
				double localsomme = 0;
				for (int i=2*N/4; i<3*N/4; i++)
				{
					localsomme += A[i];
				}
				#pragma omp atomic
				somme += localsomme;
			}
			#pragma omp section
			{
				for (int i=3*N/4; i<N; i++)
				{
					A[i] =  i;
				}
				double localsomme = 0;
				for (int i=3*N/4; i<N; i++)
				{
					localsomme += A[i];
				}
				#pragma omp atomic
				somme += localsomme;
			}
		}
	}	
	
	printf("Somme iter   : %.2lf\n", somme);
	printf("Vérification : %d\n", (N-1)*(N)/2);
	return 0;
}
