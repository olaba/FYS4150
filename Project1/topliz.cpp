//Algorithm to solve a topliz matrix
#include "project1_header.h"
#include<iostream>
using namespace std;

void topliz(int n) {

    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("results_topliz_10n.txt");}
    if(n == 100){myfile.open("results_topliz_100n.txt");}
    if(n == 1000){myfile.open("results_topliz_1000n.txt");}
    if(n == 10000000){myfile.open("results_topliz_10e7n.txt");}

    //initialize vector d of a töpliz tridiagonal matrix, and some vectors needed
    double *d = new double[n+2]; //mid diagonal
    double *y = new double[n+2]; //forcing term f(x)
    double *x = new double [n+2]; //Our numerical results
    double h = (1.0/(n+1)); //steplength

    //Setting the end values.
    d[0] = d[1] = d[n+1] = 2.0;
    x[n] = (y[n])/(d[n]);
    x[n+1] = x[0] = 0.0;

    //Initializing the töpliz matrix values.
    for(int i = 2 ; i < (n+1); i++){

        d[i] = (i+1.0)/(i);
        //std::cout << d[i] << "\n" ;

    }//end for


    //Initializing the forcing term.
    for(int i = 0 ; i < (n+2); i++){

         y[i] = h*h*(100*exp(-10*(h*(i))));

    }//end for

    //Decleare start and stop time.
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    // Start time ------------------------------------------------
    start = std::chrono::high_resolution_clock::now();

    //Forward substitution algorithm
    for(int i = 2 ; i < (n+1); i++){

         //declearing ytilde
         y[i] += (y[i-1])/(d[i-1]);

    }//end for


    //Backward substitution with ytilde and dtilde,
    for(int i = n ; i > 1; i--){

       x[i-1] = (y[i-1]+x[i])/(d[i-1]);

    }//end for

    //Stop time --------------------------------------------
    end = std::chrono::high_resolution_clock::now();
    cout << "topliz used: " <<(double) chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanoseconds for n = " << n << "\n";

    //Writing results to file
    for(int i = 0; i < (n+2); i++){

        myfile << x[i] << "\n";

    }//end for

    //closing file and deleting arrays.
    myfile.close();
    delete[] d;
    delete[] y;
    delete[] x;


}//end function
