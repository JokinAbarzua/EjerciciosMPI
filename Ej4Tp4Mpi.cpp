#include <iostream>
#include <mpi.h>
using namespace std;
int myId;
char msj[] = {"hola este es un mensaje"};
MPI_Status status;
int main(int argc, char *argv[]) {
	double tiempoinicio, tiempofin;
	MPI_Init(&argc, &argv);
	tiempoinicio = MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	if(myId == 0) {
		MPI_Send(&msj,23,MPI_CHAR,1,99,MPI_COMM_WORLD);
		cout << "envio el mensaje \"" << msj << "\"\n";
	}
	else{
		MPI_Recv(&msj,23,MPI_CHAR,0,99,MPI_COMM_WORLD,&status);
		cout << msj << endl;
	}
	tiempofin = MPI_Wtime();
	MPI_Finalize();
	if (myId == 0) cout << "Tiempo invertido en el ping-pong: " << tiempofin - tiempoinicio << endl;
	return 0;
}

