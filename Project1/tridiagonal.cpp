#include "project1_header.h"
using std::ofstream;

void tridiagonal(int n) {

//initialize and opening files depending on n
ofstream myfile;
if(n == 10){myfile.open("results_tridiagonal_10n.txt");}
if(n == 100){myfile.open("results_tridiagonal_100n.txt");}
if(n == 1000){myfile.open("results_tridiagonal_1000n.txt");}
//if(n == 10000000){myfile.open("results_tridiagonal_10e7n.txt");}

//initialize vector d and e1, e2 of a general tridiagonal matrix
double *e1 = new double[n]; //upper diagonal
double *d = new double[n]; //mid diagonal
double *e2 = new double[n]; //lower diagonal
double *y = new double[n]; //forcing term f(x)
double *x = new double [n+2]; //Our numerical results
double h = (1.0/(n+1)); //steplength

//Initializing our matrix and the forcing term.
for(int i = 0 ; i < n; i++){

    e1[i] = -1.0;
    e2[i] = -1.0;
    d[i] = 2.0;
    y[i] = h*h*(100*exp(-10*(h*(i+1))));

}//end for


//Forward substitution algorithm
for(int i = 1; i < n ; i++){

     //declearing dtilde
     d[i] -= (e1[i]*e2[i])/d[i-1];

     //declearing ytilde
     y[i] -= ((e1[i])*(y[i-1]))/d[i-1];

}//end for

//Declare x_n and the endpoints
x[n] = (y[n-1])/(d[n-1]);
x[0] = 0.0;
x[n+1] =0.0;

//Backward substitution with ytilde and dtilde
for(int i = n ; i > 1; i--){

    x[i-1] = (y[i-1] - (e2[i-1]*(x[i])))/d[i-1];

}//end for

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
