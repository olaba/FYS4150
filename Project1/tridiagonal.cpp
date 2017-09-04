#include "project1_header.h"

double tridiagonal(int n) {

//initialize and opening file
std::ofstream myfile;
myfile.open("results_tridiagonal.txt");

//initialize vector d and e1, e2 of a general tridiagonal matrix
double e1[n]; //upper diagonal (one too short?)
double d[n]; //mid diagonal
double e2[n]; //lower diagonal (one too short?)
double y[n]; //forcing term f(x)
double x[n] = {0.0}; //Our numerical results
double ex[n] = {0.0}; //The exact solution
double h = (1.0/(n+1)); //steplength

//Declearing the töpliz matrix values and forcing term.
for(int i = 0 ; i < n; i++){e1[i] = 1.0; e2[i] = 1.0; d[i] = -2.0; y[i] = h*h*(100*exp(-10*(h*(i+1))));}

//Declearing the exact answer vector and writing to file.
for(int i = 1; i < (n+1); i++){

    ex[i-1] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);
    myfile << ex[i-1] << "\n" ; //dont write the last 0 to file

}//end for

//Forward substitution algorithm
for(int i = 0; i < (n-1); i++){

     //declearing dtilde
     d[i+1] = d[i+1] - (e1[i+1]*e2[i])/d[i];

     //declearing ytilde
     y[i+1] = y[i+1] - ((e1[i+1])*(y[i]))/d[i];

}//end for

//Declare xn-1
x[n-1] = (y[n-1])/(d[n-1]);

//Backward substitution with ytilde and dtilde, and writing to file.
for(int i = n ; i > 0; i--){

    x[i-2] = (y[i-2] - (e2[i-2]*(x[i-1])))/d[i-2];
    myfile << x[i-1] << "\n";

}//end for

//closing myfile
myfile.close();

return 0.0;

}//end function
