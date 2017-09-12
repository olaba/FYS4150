#include "project1_header.h"
using namespace std;


void tridiagonal(int n) {

//initialize and opening files depending on n
ofstream myfile;
if(n == 10){myfile.open("results_tridiagonal_10n.txt");}
if(n == 100){myfile.open("results_tridiagonal_100n.txt");}
if(n == 1000){myfile.open("results_tridiagonal_1000n.txt");}
if(n == 1000000){myfile.open("results_tridiagonal_10e6n.txt");}

//initialize ¤#!dynamically allocated!#¤ arrays d and e1, e2 of a general tridiagonal matrix
double *e1 = new double[n+2]; //upper diagonal
double *d = new double[n+2]; //mid diagonal
double *e2 = new double[n+2]; //lower diagonal
double *y = new double[n+2]; //forcing term f(x)
double *x = new double [n+2]; //Our numerical results
double h = (1.0/(n+1)); //steplength

//Initializing our matrix and the forcing term.
for(int i = 0 ; i < (n+2); i++){

    e1[i] = -1.0;
    e2[i] = -1.0;
    d[i] = 2.0;
    y[i] = h*h*(100*exp(-10*(h*(i))));

}//end for

//Declare x_n and the endpoints
x[n] = (y[n])/(d[n]);
x[0] = 0.0;
x[n+1] =0.0;


//Decleare start and stop time.
clock_t start, finish;
// Start time ------------------------------------------------
start = clock();

//Forward substitution algorithm
for(int i = 2; i < (n+1) ; i++){

     //initializing dtilde
     d[i] -= (e1[i]*e2[i-1])/d[i-1];
     //std::cout << d[i] << "\n";

     //initializing ytilde
     y[i] -= ((e1[i])*(y[i-1]))/d[i-1];


}//end for


//Backward substitution with ytilde and dtilde
for(int i = n-1 ; i >= 1; i--){

    x[i] = (y[i] - (e2[i]*(x[i+1])))/d[i];

}//end for

//Stop time --------------------------------------------
finish = clock();
double time = (double) (finish - start)/((double) CLOCKS_PER_SEC);
cout << time << " is used on tridiagonal for n= " << n << "\n";

//writing results to file
for(int i = 0; i < (n+2); i++){

    myfile << x[i] << "\n";

}//end for

//closing file and deleting arrays
myfile.close();

delete[] e1;
delete[] e2;
delete[] d;
delete[] x;
delete[] y;


}//end function
