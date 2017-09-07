#include "project1_header.h"

void tridiagonal(int n) {

    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("results_tridiagonal_10n.txt");}
    if(n == 100){myfile.open("results_tridiagonal_100n.txt");}
    if(n == 1000){myfile.open("results_tridiagonal_1000n.txt");}
    //if(n == 10000000){myfile.open("results_tridiagonal_10e7n.txt");}

//initialize vector d and e1, e2 of a general tridiagonal matrix
double e1[n]; //upper diagonal (one too short?)
double d[n]; //mid diagonal
double e2[n]; //lower diagonal (one too short?)
double y[n]; //forcing term f(x)
double x[n];// = {0.0}; //Our numerical results
for (int i = 0; i < n; i++) {
    x[i] = 0.0;
}
double h = (1.0/(n+1)); //steplength

//Declearing the töpliz matrix values and forcing term.
for(int i = 0 ; i < n; i++){e1[i] = -1.0; e2[i] = -1.0; d[i] = 2.0; y[i] = h*h*(100*exp(-10*(h*(i+1))));}


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
for(int i = n ; i > 0; i--){x[i-2] = (y[i-2] - (e2[i-2]*(x[i-1])))/d[i-2];}

//writing to file
for(int i = 0; i < n; i++){myfile << x[i] << "\n";}

//closing myfile
myfile.close();


}//end function
