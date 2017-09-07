//Calculates the error between numerical value and exact.
//Reuses a lot of code from topliz.cpp and exact.cpp. This could be done smoother :)

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

void logerr(int n){

    //using the code from topliz function
    //initialize vector d and of a töpliz tridiagonal matrix
    double d[n]; //mid diagonal
    double y[n]; //forcing term f(x)
    double x[n]; //Our numerical results
    double h = (1.0/(n+1)); //steplength
    double ex[n]; //exact values


    //Declearing the töpliz matrix values and forcing term.
    for(int i = 0 ; i < n; i++){d[i] = 2.0; y[i] = h*h*(100*exp(-10*(h*(i+1))));}


    //Forward substitution algorithm
    for(int i = 1 ; i < n + 1; i++){

         //declearing dtilde
         d[i-1] = (1.0 + i)/i;

         //declearing ytilde
         y[i] = y[i] + (y[i-1])/(d[i-1]);

    }//end for

    //Declare x[n-1]
    x[n-1] = (y[n-1])/(d[n-1]);

    //Backward substitution with ytilde and dtilde,
    for(int i = n; i > 1; i--){

       x[i-2] = ((i - 1.0)/i)*(y[i-2]+x[i-1]);

    }//end for

    //Using code from exact.cpp
    for(int i = 1; i < (n+1); i++){

        ex[i-1] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);

    }//end for

    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("errors_10n.txt");}
    if(n == 100){myfile.open("errors_100n.txt");}
    if(n == 1000){myfile.open("errors_1000n.txt");}

    //calculate the error.
    for(int i = 0; i < n; i++){

        myfile << log10((fabs(ex[i]-x[i]))/(ex[i])) << "\n";

    }//end for




}
