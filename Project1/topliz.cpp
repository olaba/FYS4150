//Algorithm to solve a topliz matrix
#include "project1_header.h"

double topliz(int n) {

    //initialize and opening file
    std::ofstream myfile;
    myfile.open("results_topliz.txt");

    //initialize vector d and of a töpliz tridiagonal matrix
    double d[n]; //mid diagonal
    double y[n]; //forcing term f(x)
    double x[n]; //Our numerical results
    double ex[n]; //The exact solution
    double h = (1.0/(n+1)); //steplength


    //Declearing the töpliz matrix values and forcing term.
    for(int i = 0 ; i < n; i++){d[i] = 2.0; y[i] = h*h*(100*exp(-10*(h*(i+1))));}

    //Declearing the exact answer vector and writing to file.
    for(int i = 1; i < (n+1); i++){

        ex[i-1] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);
        myfile << ex[i-1] << "\n" ; //dont write the last 0 to file

    }//end for

    //Forward substitution algorithm
    for(int i = 1 ; i < n + 1; i++){

         //declearing dtilde
         d[i-1] = (1.0 + i)/i;

         //declearing ytilde
         y[i] = y[i] + (y[i-1])/(d[i-1]);

    }//end for

    //Declare x[n-1]
    x[n-1] = (y[n-1])/(d[n-1]);

    //Backward substitution with ytilde and dtilde, and writing to file.
    for(int i = n; i > 1; i--){

       x[i-2] = ((i - 1.0)/i)*(y[i-2]+x[i-1]);
       myfile << x[i-1] << "\n";

    }//end for


return 0.0;

}//end function
