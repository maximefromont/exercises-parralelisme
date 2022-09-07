#include <mpi.h>
#include <cstdio>
#include <unistd.h>

double f(double x)
{
  return 4 / ( 1 + (x * x));
}

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  int i;
  const int N = 100000000;
  double pi = 0.0;
  double s = 1.0 / (double)N;

  // Calculer le pi en parallele
  // A FAIRE ...
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  for(int i = rank; i < N; i = i+size) {
    pi = pi + (s * (f(i*s) + f((i+1) * s)) / 2);
  } 

  printf("Somme pi = %lf depuis %d\n", pi, rank);

  // Afficher le pi
  if (rank == 0) { 
    double piR;
    for(int i = 1; i < size; i++) {
      MPI_Recv(&piR, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      pi = pi + piR; 
    }
    printf("Pi: %lf\n", pi); 
  } else {
    MPI_Send(&pi, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
