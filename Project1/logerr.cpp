//Calculates the error between numerical value from topliz.cpp and exact.
//Reuses a lot of code from topliz.cpp and exact.cpp.
//This could be done a lot smoother, if we didn't write to file :)

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

void logerr(int n){

    double *d = new double[n+2]; //mid diagonal
    double *y = new double[n+2]; //forcing term f(x)
    double *x = new double [n+2]; //numerical results
    double *ex = new double [n+2]; //exact results
    double h = (1.0/(n+1)); //steplength

    //Setting the end values.
    d[n+1] = d[0] = 2.0;

    //Calculating exact answer
    for(int i = 0; i < (n+2); i++){

       ex[i] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);

    }//end for

    //Initializing the töpliz matrix values.
    for(int i = 2 ; i < (n+2); i++){

        d[i-1] = (i+1.0)/( (double) i);

    }//end for


    //Initializing the forcing term.
    for(int i = 0 ; i < (n+1); i++){

        y[i] = h*h*(100*exp(-10*(h*(i))));

    }//end for

    //START TIMING HERE

    //Forward substitution algorithm
    for(int i = 1 ; i < (n + 1); i++){

         //declearing ytilde
         y[i] += (y[i-1])/(d[i-1]);

    }//end for

    //Declare x[n-1] and endpoints
    x[n] = (y[n])/(d[n]);
    x[n+1] = x[0] = 0.0;


    //Backward substitution with ytilde and dtilde,
    for(int i = n; i > 1; i--){

       x[i-1] = (y[i-1]+x[i])/(d[i-1]);

    }//end for


    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("errors_10n.txt");}
    if(n == 100){myfile.open("errors_100n.txt");}
    if(n == 1000){myfile.open("errors_1000n.txt");}

    //calculate the error. Not the endpoints where we just sat our values.
    for(int i = 1; i < n+1; i++){

        myfile << log10((fabs(ex[i]-x[i]))/(ex[i])) << "\n";

    }//end for

}
