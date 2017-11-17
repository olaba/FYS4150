/*Program to solve the two-dimensional Ising model
The coupling constant J = 1
Boltzmann’s constant = 1, temperature has thusforementioned dimension energy
Metropolis sampling is used. Periodic boundary conditions.
Heavily based on the work of Mortimer Hjort Jensen, because (total workload > work capacity) throughout November 2017.
Added some comments for our own understanding, and wrote the body of read_input og output.
This version touches paralellization with MPI. Giovanni for president!!!
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include "lib.h"
#include "project4real_header.h"
#include "mpi.h"


//Initializing a file object
ofstream ofile;

// Inline function for periodic boundary conditions
// Written as inline to make more effective?
inline int periodic(int i,int limit, int add) {
return (i+limit+add) % (limit);
}

int main(int argc, char* argv[])
{
int my_rank, numprocs;
MPI_Init (&argc, &argv); 
MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

    //Some global variables
    char *outfilename; //Name on outfile
    long idum; //The seed for random number generator?
    int **spin_matrix, n_spins, mcs; //The lattice itself, lattice dimension, number of monte carlo cycles.
    int accepted = 0; //number of accepted flips.
    double w[17], average[5], initial_temp, final_temp, E, M, temp_step; //Array of DeltaE (w), average, initial temperature, final temperature, Energy, Magnetisation, stepsize temperature.


if(my_rank == 0){
    // Read in output file, abort if there are too few command-line arguments
    if ( argc <= 1 ){cout << "Bad Usage: " << argv[0] << " read also output file on same line " << endl;}
    else {outfilename=argv[1];}

    //Opening file
    ofile.open(outfilename);

    //Read in initial values such as size of lattice, temp and cycles
    read_input(n_spins, mcs, initial_temp, final_temp, temp_step, argv);
}

MPI_Bcast(&n_spins, 1, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Bcast(&mcs, 1, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Bcast(&initial_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
MPI_Bcast(&final_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
MPI_Bcast(&temp_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    //Initialize lattice matrix from "lib.h" version. No armadillo, thats chillo
    spin_matrix = (int **) matrix(n_spins, n_spins, sizeof( int ));
    idum = time(NULL)-my_rank; // random starting point

    //Loop over chosen temperature domain
    //for (double temp = initial_temp; temp <= final_temp; temp+=temp_step){

        double temp = initial_temp;

        //    initialise energy and magnetization
        E = M = 0.; //EMO :(

        // setup array for possible energy changes.
        for(int de =-8; de <= 8; de++) w[de+8] = 0;
        for(int de =-8; de <= 8; de += 4) w[de+8] = exp(-de/temp);

         // initialise array for expectation values
         for(int i = 0; i < 5; i++) average[i] = 0.0;

         //Make the matrix, and calculate E and M
         initialize(n_spins, temp, spin_matrix, E, M);

         //Monte Carlo simulation, loop over number of cycles
         for (int cycles = 1; cycles <= mcs; cycles++){

               //This is the metropolis algo itself
               Metropolis(n_spins, idum, spin_matrix, E, M, w, accepted);

               // update expectation values. 
               average[0] += E;    average[1] += E*E;
               average[2] += M;    average[3] += M*M; average[4] += fabs(M);

        }//End MC
for(int i = 0; i < 5; i ++)
MPI_Allreduce(&average[i], &average[i], 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);


if(my_rank == 0){
   //print results 
   output(n_spins, mcs*numprocs, temp, average);

    double accepted_per_mcs = (double) accepted/mcs;
    cout << accepted_per_mcs << endl;
    ofile.close(); // close output file
}
    //}//end time loop

    free_matrix((void**) spin_matrix); // free memory
MPI_Finalize();
    return 0;
}


//Function that reads input from terminal
void read_input(int& n_spins, int& mcs, double& initial_temp, double& final_temp, double& temp_step, char* argv[]){

//read values from argument vector
n_spins = atoi(argv[2]);
mcs = atoi(argv[3]);
initial_temp = atof(argv[4]);
final_temp = atof(argv[5]);
temp_step = atof(argv[6]);

}

//Function that initialize an spin lattice and calculates initial E and M
void initialize(int n_spins, double temp, int** spin_matrix, double& E, double& M, long* idum){

//Initialize magnetization and calculate M
    for(int y = 0; y < n_spins; y++){
        for(int x = 0; x < n_spins; x++){



                //spin orientation "ground state". If temp low enough, all spins are aligned one way (up).
                spin_matrix[y][x] = 1; //comment out if you want random start config #vivelabruteforce!

                //A sad try to make a random configuration. Comment out if you want "all up"  initial config. But remember to uncomment
                //double rand = ran1(&idum1);
                //if (rand < 0.5){spin_matrix[y][x] = 1;}
                //else{spin_matrix[y][x] = -1;}




            //Add current site spin to total magnetization
            M += (double) spin_matrix[y][x];
        }
    }

//Calculate initial energy
    for(int y = 0; y < n_spins; y++){
        for(int x = 0; x < n_spins; x++){

            //Calculating Energy. Why minus?
            E -= (double) spin_matrix[y][x]*(spin_matrix[periodic(y,n_spins,-1)][x] + spin_matrix[y][periodic(x,n_spins,-1)]);

        }
    }


}

//The metropolis algorithm
void Metropolis(int n_spins, long& idum, int** spin_matrix, double& E, double& M, double* w, int& accepted){

//loop over all spins
    for(int y = 0; y < n_spins; y++){
        for(int x = 0; x < n_spins; x++){

        //Find random position
        int ix = (int) (ran1(&idum)*(double)n_spins);
        int iy = (int) (ran1(&idum)*(double)n_spins);

        //Calculate Delta E
        int DeltaE = 2*spin_matrix[iy][ix]*(spin_matrix[iy][periodic(ix,n_spins,-1)] + spin_matrix[periodic(iy,n_spins,-1)][ix] +
                spin_matrix[iy][periodic(ix,n_spins,1)] + spin_matrix[periodic(iy,n_spins,1)][ix]);

        //Perform the Metropolis test
        if( ran1(&idum) <= w[DeltaE+8]){

            //We implement the accepted flip
            spin_matrix[iy][ix] *= -1;

            //We update the Magnetization
            M += (double) 2*spin_matrix[iy][ix];

            //We update the Energy
            E += (double) DeltaE;

            //Update counting variable for 4c)
            accepted += 1;

         }//end "random number if"

        }//end x
    }//end y
}//end Metropolis


//Print to file results
void output(int n_spins, int mcs, double temp, double* average){

//Dividing factor, the number of mcs
double norm = 1.0/((double) mcs*n_spins*n_spins);

//Divide all variables by mcs
//Energy
average[0] = average[0]*norm;
//Energy²
average[1] = average[1]*norm;
//Magnetizm
average[2] = average[2]*norm;
//Magnetizm²
average[3] = average[3]*norm;
//Magentizm absolute value
average[4] = average[4]*norm;

//Calculate some variances, heat capacity and susceptebility
//Calculate Evariance
double Evariance = average[1] - (average[0]*average[0]);
//Calculate Mvariance
double Mvariance = average[3] - (average[2]*average[2]);
//Calculate Cv
double Cv = Evariance/(temp*temp);
//Calculate X
double X = Mvariance/temp;

ofile << setiosflags(ios::showpoint | ios::uppercase);
ofile << setw(15) << setprecision(8) << temp;
ofile << setw(15) << setprecision(8) << average[0];
ofile << setw(15) << setprecision(8) << Cv;
ofile << setw(15) << setprecision(8) << average[2];
ofile << setw(15) << setprecision(8) << X;
ofile << setw(15) << setprecision(8) << average[4] << endl;

}//end output

