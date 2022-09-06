#include <mpi.h>
#include <cstdio>
#include <unistd.h>

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("I am core %d out of %d\n", rank, size - 1);

  if(rank%2 == 0) {
    if(rank + 1 <= size - 1) {
      MPI_Send(&rank, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
      printf("I just sent %d to %d\n", rank, rank+1);
    }
  } else {
    int rankR;
    MPI_Recv(&rankR, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("I just recieved %d from %d\n", rankR, rank-1);
    
  }

  MPI_Finalize();
  return 0;
}
