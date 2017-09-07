//Algorithm to solve a topliz matrix
#include "project1_header.h"

void topliz(int n) {

    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("results_topliz_10n.txt");}
    if(n == 100){myfile.open("results_topliz_100n.txt");}
    if(n == 1000){myfile.open("results_topliz_1000n.txt");}
    //if(n == 10000000){myfile.open("results_topliz_10e7n.txt");}

    //initialize vector d of a töpliz tridiagonal matrix, and some vectors needed
    double *d = new double[n]; //mid diagonal
    double *y = new double[n]; //forcing term f(x)
    double *x = new double [n+2]; //Our numerical results
    double h = (1.0/(n+1)); //steplength


    //Declearing the töpliz matrix values and forcing term.
    for(int i = 0 ; i < n; i++){

        d[i] = (1.0 + (i+1))/(i+1);
        y[i] = h*h*(100*exp(-10*(h*(i+1))));

    }//end for

    //START TIMING HERE

    //Forward substitution algorithm
    for(int i = 1 ; i < (n + 1); i++){

         //declearing ytilde
         y[i] = y[i] + (y[i-1])/(d[i-1]);

    }//end for

    //Declare x[n-1] and endpoints
    x[n] = (y[n])/(d[n]);
    x[0] = 0.0;
    x[n+2] = 0.0;


    //Backward substitution with ytilde and dtilde,
    for(int i = n; i > 1; i--){

       x[i-1] = (y[i-1]+x[i])/(d[i-1]);

    }//end for

    //END TIMING HERE

    //Writing results to file
    for(int i = 0; i < n; i++){

        myfile << x[i] << "\n";

    }//end for

    //closing file and deleting arrays.
    myfile.close();
    delete[] d;
    delete[] y;
    delete[] x;


}//end function
