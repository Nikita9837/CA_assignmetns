#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{   	
 MPI_Init(&argc, &argv);
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);

int number,num1;
if (world_rank == 0) {
 MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("branch 0 received number %d from branch 1\n",number);
           
} else if (world_rank == 1) {
    number = 100000;
    MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
}
 


if(world_rank==0){
	 num1=number*(0.23);
           MPI_Send(&num1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
}
else if(world_rank==1){
	MPI_Recv(&num1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("branch 1 received number %d from branch 0\n",num1);
}

     MPI_Finalize();
   }
