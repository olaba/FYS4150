//Code for project 5 in FYS4150
//Made by Ingvild, Hanne and Ola
//No copyrights or copywrongs, but still inspired by the work of Morten H. Jensen from project 4.
//Thanks to the one and only Jostein for discussions, help and inspiration.
//Also thanks to Håkon for late night studies.
//Most importantly the and the introuduction of [stepnum-2] and [1] for boundary calculations.
//No elegant coding implemented here, a lot of brute force. Sorry for that, but it still gives us OK results in reasonable time
//IMPORTANT: For reasonable results in 1D periodic, you need to have armadillo version later than 4.600!! 


#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
//#include <armadillo> //Comment out when working from forskningsparken where no armadillo is to be found
#include <cmath>
#include "project5header.h"

using namespace std;
//using namespace arma; //Comment out when working from forskningsparken where no armadillo is to be found

//Initializing file objects for 1D and 2D;
ofstream ofile;

int main(int argc, char *argv[])
{

    //------------------------------------ Start up stuff -----------------------------------------------//

    //Declearing some global variables
    double dx, delta_time, initialtime, finaltime;
    int dimension, option;
    char* outfilename;

    // Read in output file, abort if there are too few command-line arguments
    if ( argc <= 1 ){cout << "Bad Usage: " << argv[0] << " read also output file on same line " << endl;}
    else {outfilename=argv[1];}

    //Opening file
    ofile.open(outfilename);

    //Read inputs, at set up inital psi and vorticity
    read_input(dx, delta_time, finaltime, initialtime, dimension, option, argv);

    //Set time equal to initialtime
    double time = initialtime;

    //calculating number of stepshttps://www.tvedestrandsposten.no/
    int stepnum = (int) ((1/dx) + 1);

    //allocates memory for psi and vorticity and some vectors needed in tridiagonal function.
    double *psi = new double[stepnum]; //Stream function array
    double *vorticity = new double[stepnum]; //Vorticity array
    double *e1 = new double[stepnum]; //upper diagonal
    double *d = new double[stepnum]; //mid diagonal
    double *e2 = new double[stepnum]; //lower diagonal
    double *force = new double[stepnum]; //forcing term in tridiagonal algo
    double *first_vorticity = new double [stepnum]; //vorticity vector for centered difference 1D
    double **temp_vorticity2D = new double* [stepnum]; //vorticity vector for 2D forward difference.
    double **psi2D = new double* [stepnum]; //2D psi
    double **vorticity2D = new double* [stepnum]; //2D vorticity
    double **first_vorticity2D = new double* [stepnum]; //2D temporarly vorticity used in centered diff
    double **psi2D_temp = new double* [stepnum]; //2D temporarly psi used in iterative solver


    //initializes the psi and vorticity arrays.
    if(dimension == 1){initialize(psi, vorticity, stepnum, option, dx);}
    if(dimension == 2){initialize2D(psi2D,vorticity2D,stepnum,dx, option);}

    //Initialize the temporary arrays
    first_vorticity = vorticity;
    psi2D_temp = psi2D;

    //initializing the force 1D array
    for(int i = 0; i < (stepnum); i++){force[i] = vorticity[i]*dx*dx;}

    //precalculating constants needed in the different schemes.
    //Named in honour of ourselves, and jostein.
    //Sorry about this, but alpha, beta etc. doesn't make it any better, just less fun.
    double ola = delta_time/(2*dx);
    double ingvild = delta_time/(dx);
    double hanne = 4*(dx*dx); //since dx = dy
    double jostein = dx*dx;
    double jostein2 = jostein*jostein;


    //-------------------------------------- Calculations and write to file  ---------------------------//

    while(time < finaltime){

        //One dimension
        if(dimension == 1){

        //write to file
        output(psi,vorticity,stepnum);

        //Calculate next step with forward or centered method. Comment in/out the one you want
        //forward_diff_solidb(psi, vorticity, stepnum, ola);
        center_diff_solidb(psi,vorticity, first_vorticity, stepnum, ingvild, ola, time);
        //forward_diff_periodicb(psi,vorticity,stepnum,ola);
        //center_diff_periodicb(psi,vorticity, first_vorticity, stepnum, ingvild, ola, time);

        //update the force 1D array
        for(int i = 0; i < (stepnum); i++){force[i] = vorticity[i]*dx*dx;}

        //Reuse project 1 code or armadillo (periodic case) to calculate psi, comment in/out the one you want.
        tridiagonal_solidb(psi, force, e1, e2, d, dx, stepnum);
        //tridiagonal_periodicb(psi, force, e1, e2, d, dx, stepnum);
	//Armadillo_1D_periodic_solver(psi,force,stepnum);

        }//end 1D


        //Two dimensions
        if(dimension == 2){

        //Write to file
        output2d(psi2D, vorticity2D, stepnum);

        //Calculate next time step vorticity
        centered_diff_solidb_2D(psi2D,vorticity2D,first_vorticity2D,stepnum,ingvild,ola,time);

        //Iterative Jacobi solver to find psi next time step
        Jacobi_Iterative_solidb_2D(psi2D,psi2D_temp,vorticity2D,stepnum,jostein,hanne,jostein2);

        }

        //adds a time step
        time += delta_time;

    }

    cout << "great success"<< endl;

  return 0;

}//end main


//----------------------------------- 1D Functions -----------------------------------------------------//

void read_input(double& dx, double& delta_time, double& finaltime, double& initialtime,int& dimension, int& option, char* argv[]){

        //reading in variables
        dx = atof(argv[2]);
        delta_time = atof(argv[3]);
        initialtime = atof(argv[4]);
        finaltime = atof(argv[5]);
        dimension = atof(argv[6]);
        option = atoi(argv[7]);

}

void initialize(double*& psi, double*& vorticity, int stepnum, int option, double dx){

    //Setting up initial values for psi and vorticity (option = 1 ---> sine)
    if(option == 1){
        for(int i = 0; i < stepnum; i++ ){

            psi[i] = sin(4*M_PI*i*dx);
            vorticity[i] = -16*M_PI*M_PI*cos(4*M_PI*i*dx);

        }//end for
    }//end if

    //Setting up initial values for psi and vorticity (option = 2 --> exp)
    if(option == 2){
        for(int i = 0; i < stepnum; i++){

            psi[i] = exp(-(pow(((dx*i - 0.5)/0.1),2)));
            vorticity[i] = exp(-100*(-0.5 + dx*i)*(-0.5 + dx*i))*(9800. - 40000*dx*i + 40000.*(dx*i*dx*i)); //wolframalpha

        }
    }
}

void output(double*& psi, double*& vorticity, int stepnum){

    ofile << setiosflags(ios::showpoint | ios::uppercase);

    for(int i = 0; i < stepnum; i++){

        ofile << setw(15) << setprecision(8) << psi[i];
        ofile << setw(15) << setprecision(8) << vorticity[i] << endl;
    }


}

void tridiagonal_solidb(double*& psi, double*& force, double*& e1, double*& e2, double*& d, double dx, int stepnum){


    //Initializing our matrix and the forcing term.
    for(int i = 0 ; i < stepnum; i++){

        e1[i] = 1.0;
        e2[i] = 1.0;
        d[i] = -2.0;


    }//end for

    //Declare x_n and the endpoints
    psi[stepnum-1] = 0.0;
    psi[0] = 0.0;

    //Forward substitution algorithm
    for(int i = 2; i < stepnum ; i++){

         //initializing dtilde
         d[i] -= (e1[i]*e2[i-1])/d[i-1];

         //initializing ytilde
         force[i] -= ((e1[i])*(force[i-1]))/d[i-1];


    }//end for


    //Backward substitution with ytilde and dtilde
    for(int i = (stepnum-2); i >= 1; i--){

        psi[i] = (force[i] - (e2[i]*(psi[i+1])))/d[i];

    }//end for


}

void forward_diff_solidb(double*& psi, double*& vorticity, int stepnum, double ola){


    //Set the boundary conditions for solid walls (just to be sure!)
    psi[0] = 0;
    psi[stepnum-1] = 0;

    //loop over all interior points
    for(int i = 1; i < (stepnum-1); i++){

    double temp_vorticity = vorticity[i];
    double temp_psi1    = psi[i+1];
    double temp_psi2    = psi[i-1];

    vorticity[i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;

    }//end for



}

void center_diff_solidb(double*& psi, double*& vorticity, double*& first_vorticity, int stepnum, double ingvild, double ola, double time){

    //Calculate forward on first step
    if(time == 0){

    //Update first_vorticity
    first_vorticity = vorticity;

    //Calculate first time step with loop over all points except boundary points
    for(int i = 1; i < (stepnum-1); i++){

    double temp_vorticity = vorticity[i];
    double temp_psi1    = psi[i+1];
    double temp_psi2    = psi[i-1];

    vorticity[i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;

    }
    }

    //Centered on next steps
    if(time != 0){

    //Calculate first time step with loop over all points except boundary points
    for(int i = 1; i < (stepnum-1); i++){

    //Decleare and initialize some temporare variables
    double temp_first_vorticity = first_vorticity[i];
    double temp_psi1    = psi[i+1];
    double temp_psi2    = psi[i-1];

    //Update first_vorticity
    first_vorticity = vorticity;

    //Calculate new vorticity
    vorticity[i] = temp_first_vorticity + (temp_psi2 - temp_psi1)*ingvild;

    }

    }//end for

}

void forward_diff_periodicb(double* psi, double* vorticity, int stepnum, double ola){
	
    //Saving some temporary values
    double temp_vorticity0 = vorticity[0];
    double temp_vorticity_end = vorticity[stepnum - 1];

    //loop over all interior points
    for(int i = 1; i < (stepnum-1); i++){

        //Save some temporary variables
        double temp_vorticity = vorticity[i];
        double temp_psi1    = psi[i+1];
        double temp_psi2    = psi[i-1];

        //Calculate vorticity at next timestep
        vorticity[i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;


    }//end for

    //Calculating boundary values
    vorticity[0] = temp_vorticity0 + (psi[stepnum - 2] - psi[1])*ola;
    vorticity[stepnum - 1] = vorticity[0];

}

void center_diff_periodicb(double*& psi, double*& vorticity, double*& first_vorticity, int stepnum, double ingvild, double ola, double time){

    //Calculate forward on first step
    if(time == 0){

    //Save some temporary variables
    double temp_vorticity0 = vorticity[0];
    double temp_vorticity_end = vorticity[stepnum - 1];


    //Calculate first time step with loop over all points except boundary points
    for(int i = 1; i < (stepnum-1); i++){

    double temp_vorticity = vorticity[i];
    double temp_psi1    = psi[i+1];
    double temp_psi2    = psi[i-1];

    vorticity[i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;

    }

    //Calculating boundary values
    vorticity[0] = temp_vorticity0 + (psi[stepnum-2] - psi[1])*ola;
    vorticity[stepnum - 1] = vorticity[0];

    }

    //Centered on next steps
    if(time != 0){

    //Calculate next time step with loop over all points except boundary points
    for(int i = 1; i < (stepnum-1); i++){

    //Decleare and initialize some temporare variables
    double temp_first_vorticity = first_vorticity[i];
    double temp_psi1    = psi[i+1];
    double temp_psi2    = psi[i-1];

    //Savce current vorticity
    first_vorticity = vorticity;

    //Calculate new vorticity
    vorticity[i] = temp_first_vorticity + (temp_psi2 - temp_psi1)*ingvild;

    }

    //Calculating boundary values
    vorticity[0] = first_vorticity[0] + (psi[stepnum-2] - psi[1])*ingvild;
    vorticity[stepnum - 1] = first_vorticity[stepnum-1] + (psi[stepnum - 2] - psi[1])*ingvild;

    }//end else




}

void tridiagonal_periodicb(double*& psi, double*& force, double*& e1, double*& e2, double*& d, double dx, int stepnum){


    //Initializing our matrix and the forcing term.
    for(int i = 0 ; i < stepnum; i++){

        e1[i] = 1.0;
        e2[i] = 1.0;
        d[i] = -2.0;


    }//end for

    //Calculating lower endpoint dtile and ytilde explicit with periodic boundary conditions (The Jostein condition: stepnum - 2 = much better )
    d[0] -= (e1[0]*e2[stepnum-2])/d[stepnum-2];
    force[0] -= ((e1[stepnum-2])*(force[stepnum-2]))/d[stepnum-2];

    //Forward substitution algorithm
    for(int i = 1; i < stepnum ; i++){

         //initializing dtilde
         d[i] -= (e1[i]*e2[i-1])/d[i-1];

         //initializing ytilde
         force[i] -= ((e1[i])*(force[i-1]))/d[i-1];


    }//end for

    //Calculating upper endpoint explicit with periodic jostein boundary conditions
    //error arises from psi[1] which is taken from timestep n and not n+1.
    psi[stepnum-1] = (force[stepnum-1] - (e2[stepnum-2]*(psi[1])))/d[stepnum-2];


    //Backward substitution with ytilde and dtilde
    for(int i = (stepnum-2); i >= 0; i--){

        psi[i] = (force[i] - (e2[i]*(psi[i+1])))/d[i];

    }//end for

    //prints the error using the modified jostein method
    cout << "error" << fabs(psi[0] - psi[stepnum-1]) << endl;
}

//Comment out due to no armadillo in forskningsparken
/*void Armadillo_1D_periodic_solver(double*& psi, double*& force, int stepnum){
    
    //initializing vectors and matrix
    vec psivec(stepnum);
    vec forcevec(stepnum-1);
    vec dvec(stepnum-1, fill::ones);
    vec evec(stepnum-2, fill::ones);
    mat A(stepnum-1, stepnum-1, fill::zeros);
    
    //for loop to convert force from array to armadillo vectors
    for(int i = 0; i < (stepnum-1); i++){
        
        forcevec(i) = -force[i];
        
    }//end for
    
    //Initializing our matrix and the forcing term.  
    A.diag() = 2*dvec;
    A.diag(1)= -evec;
    A.diag(-1)= -evec;
    A(0,stepnum-2) = -1;
    A(stepnum-2,0) = -1;

    //Solve system with armadillo-function
    vec solution = solve(A, forcevec);
	
	for(int i=0; i<stepnum-1;i++) {
		psi[i] = solution(i);
    }

	psi[stepnum-1] = solution(0);

}//end function

*/
//----------------------------------- 2D functions -----------------------------------------------------//

void initialize2D(double **&psi2D, double **&vorticity2D, int stepnum, double dx, int option){

    psi2D = new double*[stepnum];
    vorticity2D = new double*[stepnum];

    if(option == 1){	
    for(int j = 0; j < stepnum; j++){

        psi2D[j] = new double[stepnum];
        vorticity2D[j] = new double[stepnum];
	
        for(int i = 0; i < stepnum; i++){


                psi2D[j][i] = sin(M_PI*j*dx)*sin(4*M_PI*i*dx);  //Assumed a periodicity in y direction as well
                vorticity2D[j][i] = -(17)*M_PI*M_PI*sin(M_PI*j*dx)*sin(4*M_PI*i*dx); //Vorticity = second derivative of psi.
		
                if((i==0)|| (j==0)){

                    psi2D[j][i] = 0.0;
                    vorticity2D[j][i] = 0.0;
                }
        }//end i
    }//end j
    }//end option 1


    if(option == 2){
    for(int j = 0; j < stepnum; j++){

        psi2D[j] = new double[stepnum];
        vorticity2D[j] = new double[stepnum];
	
        for(int i = 0; i < stepnum; i++){


                psi2D[j][i] = exp(-(pow(((dx*i - 0.5)/0.1),2)))*(exp(-(pow(((dx*j - 0.5)/0.1),2)))); //Assume exp in y dir as well
                vorticity2D[j][i] = exp(-100*(-0.5 + i*dx)*(-0.5 + i*dx) - 100*(-0.5 + j*dx)*(-0.5 + j*dx))*(19600. - 40000.*i*dx + 40000.*(i*dx)*(i*dx) - 40000.*(j*dx) + 40000.*(j*dx)*(j*dx)); //Vorticity = second derivative of psi.
		
                if((i==0)||(j==0)){

                    psi2D[j][i] = 0.0;
                    vorticity2D[j][i] = 0.0;

                }



        }//end i
    }//end j
    }//end option 2


}

void output2d(double**& psi2D, double**& vorticity2D, int stepnum){

    for(int j = 0; j < stepnum; j++){

        //Writes the psi and vorticity to each file
        for(int i = 0; i < stepnum; i++){
        ofile << ' ' << psi2D[j][i];
        }
        ofile << endl;
    }


}

void forward_diff_solidb_2D(double** psi2D, double** vorticity2D, int stepnum, double ola){

    for(int j = 0; j<stepnum; j++){

        //Set the boundary conditions for solid walls (just to be sure!)
        psi2D[j][0] = 0;
        psi2D[j][stepnum-1] = 0;

        //loop over all interior points
        for(int i = 1; i < (stepnum-1); i++){

        double temp_vorticity = vorticity2D[j][i];
        double temp_psi1    = psi2D[j][i+1];
        double temp_psi2    = psi2D[j][i-1];

        vorticity2D[j][i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;

        }//end for col

    }//end for rows

}

void centered_diff_solidb_2D(double**& psi2D, double**& vorticity2D, double**& first_vorticity2D, int stepnum, double ingvild, double ola, double time){

//forward solution in the first step
if (time == 0){
	
    first_vorticity2D = vorticity2D;

    for(int j = 0; j<stepnum; j++){

    //Set the boundary conditions for solid walls (just to be sure!)
    psi2D[j][0] = 0;
    psi2D[j][stepnum-1] = 0;

    //loop over all interior points
    for(int i = 1; i < (stepnum-1); i++){

    double temp_vorticity = vorticity2D[j][i];
    double temp_psi1    = psi2D[j][i+1];
    double temp_psi2    = psi2D[j][i-1];

    vorticity2D[j][i] = temp_vorticity + (temp_psi2 - temp_psi1)*ola;
    }//end for i
    }//end for j
}//end if time == 0

else{

    for(int j = 0; j<stepnum; j++){

    //Calculate first time step with loop over all points except boundary points
    for(int i = 1; i < (stepnum-1); i++){

    //Decleare and initialize some temporare variables
    double temp_first_vorticity = first_vorticity2D[j][i];
    double temp_psi1    = psi2D[j][i+1];
    double temp_psi2    = psi2D[j][i-1];

    //Update first_vorticity
    first_vorticity2D = vorticity2D;

    //Calculate new vorticity
    vorticity2D[j][i] = temp_first_vorticity + (temp_psi2 - temp_psi1)*ingvild;

    }//end for i
    }//end for j
}//end else

}

void forward_diff_periodicb_2D(double**& psi2D, double**& vorticity2D, double**& temp_vorticity2D, int stepnum, double ola){
	
    //Update first_vorticity temporarly array
    temp_vorticity2D = vorticity2D;

    for(int j = 0; j<stepnum; j++){

	//Set the periodic boundaries at right and left endpoints for all rows	
	vorticity2D[j][0] = temp_vorticity2D[j][0] + (psi2D[j][stepnum - 2] - psi2D[j][1])*ola;
    	vorticity2D[j][stepnum-1] = temp_vorticity2D[j][stepnum-1] + (psi2D[j][stepnum - 2] - psi2D[j][1])*ola;	

        //loop over all interior points
        for(int i = 1; i < (stepnum-1); i++){

        vorticity2D[j][i] = temp_vorticity2D[j][i] + (psi2D[j][i-1]- psi2D[j][i+1])*ola;
	
	}//end for col

    }//end for rows

}

void Jacobi_Iterative_solidb_2D(double**& psi2D, double**& psi2D_temp, double**& vorticity2D, int stepnum, double jostein, double hanne, double jostein2){

//Declearing the iteration limit and counter
int maxiter = 100;
int iter = 0;


//Calculate next step by iterative method which uses the four neighbours
while(iter < maxiter){

    //Declaring temporary psi
    psi2D_temp = psi2D;
	
    //Calculate the interior psi's. Endpoint just stays zero.
    for(int j = 1; j < (stepnum -1); j++){
        for(int i = 1; i < (stepnum - 1); i++){

        psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][i-1]) + (psi2D_temp[j+1][i] + psi2D_temp[j-1][i])) - jostein2*vorticity2D[j][i])/hanne;

        }//end i
    }//end j

 //Update iteration counter
 iter += 1;

}//end iteration while

}

void Jacobi_Iterative_periodicb_2D(double**& psi2D, double**& psi2D_temp, double**& vorticity2D, int stepnum, double jostein, double hanne, double jostein2){

//Declearing the iteration limit and counter
int maxiter = 100;
int iter = 0;


//Calculate next step by iterative method which uses the four neighbours. Brute force and ugly code. sorry sorry sorry.
while(iter < maxiter){

    //Declaring temporary psi
    psi2D_temp = psi2D;

    for(int j = 0; j < (stepnum); j++){
        for(int i = 0; i < (stepnum); i++){
	
	//The points and corners on left border ----------------------------------------------------------------------//
        if((i == 0)){
	
		//upper left corner. OK
		if(j==(stepnum-1)){	
	        		psi2D[j][i] = (jostein*((psi2D_temp[j][1] + psi2D_temp[j][stepnum-2]) + (psi2D_temp[1][i] + 			psi2D_temp[j-1][i])) - jostein2*vorticity2D[j][i])/hanne;
		}

		//lower left corner OK
		else if(j==0){
        	psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][stepnum-2]) + (psi2D_temp[j+1][i] + psi2D_temp[stepnum-2][i])) - 			jostein2*vorticity2D[j][i])/hanne;
		}
	
		//Internal points on left border OK
		else if(j != 0 && j!= (stepnum-1)){
		psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][stepnum - 2]) + (psi2D_temp[j+1][i] + psi2D_temp[j-1][i])) - 			jostein2*vorticity2D[j][i])/hanne;

        	}
	}//end left endpoints



	//Points and corners on right border----------------------------------------------------------------------//
        if(i == (stepnum-1)){

		//upper right corner OK
		if(j == (stepnum-1)){
		psi2D[j][i] = (jostein*((psi2D_temp[j][1] + psi2D_temp[j][i-1]) + (psi2D_temp[1][i] + psi2D_temp[j-1][i])) - 			jostein2*vorticity2D[j][i])/hanne;
		}
	
		//lower right corner OK
		else if(j == 0){
        	psi2D[j][i] = (jostein*((psi2D_temp[j][1] + psi2D_temp[j][i-1]) + (psi2D_temp[j+1][i] + psi2D_temp[stepnum-2][i])) -    	  	jostein2*vorticity2D[j][i])/hanne;
		}
		
		//Internal points on right border OK
		else if(j != 0 && j!= (stepnum-1)){
		psi2D[j][i] = (jostein*((psi2D_temp[j][1] + psi2D_temp[j][i-1]) + (psi2D_temp[j+1][i] + psi2D_temp[j-1][i])) - 			jostein2*vorticity2D[j][i])/hanne;
		}
        }//end right endpoints

	//Points on upper border------------------------------------------------------------------------//
        if(j == (stepnum-1)){
	
		//interior points on upper border (corners already been taken)	OK
		if(i != 0 && i != (stepnum-1)){
		psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][i-1]) + (psi2D_temp[1][i] + psi2D_temp[j-1][i])) - 	  			jostein2*vorticity2D[j][i])/hanne;}

        	}//end upper endpoints

	//Points on lower border ------------------------------------------------------------------------//
        if(j == 0){
	
		//interior points on lower border (corners already been taken) OK
		if(i != 0 && i != (stepnum-1)){	
		psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][i-1]) + (psi2D_temp[j+1][i] + psi2D_temp[stepnum-2][i])) - 			jostein2*vorticity2D[j][i])/hanne;
		}
        	}//end lower endpoints
		
	//Interior interior points. hehe.---------------------------------------------------------------// 
	if(i != 0 && j!= 0 && j != (stepnum-1) && i != (stepnum-1))  {
        psi2D[j][i] = (jostein*((psi2D_temp[j][i+1] + psi2D_temp[j][i-1]) + (psi2D_temp[j+1][i] + psi2D_temp[j-1][i])) - 	  	  
        jostein2*vorticity2D[j][i])/hanne;
	}

        
      }//end i
    }//end j


 //Update iteration counter
 iter += 1;

}//end iteration while

}



















