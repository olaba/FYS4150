#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    //number of mesh points
    int n = 100;

    //initialize and opening file
    ofstream myfile;
    myfile.open("results.txt");

    //initialize vector d and e in the matrix of poisson eq.
    double e[n];
    double d[n];
    double y[n]; //forcing term f(x)
    double x[n] = {0.0}; //Our numerical results
    double ex[n] = {0.0}; //The exact solution
    double h = (1.0/(n-1)); //steplength

     //Declearing the töpliz matrix values and forcing term.
    for(int i = 0; i < n; i++){e[i] = 1.0; d[i] = -2.0; y[i] = h*h*(100*exp(-10*(h*i)));}

    //Declearing the exact answer vector and writing to file.
    for(int i = 0; i < n; i++){

        ex[i] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);
        myfile << ex[i] << "\n" ;

    }//end for

    //Forward substitution algorithm
    for(int i = 0; i < n; i++){

         //declearing dtilde
         d[i+1] = d[i+1] - (pow(e[i],2.0))/d[i];

         //declearing ytilde
         y[i+1] = y[i+1] - ((e[i])*(y[i]))/d[i];

    }//end for

    //first entry of backwardsubstitution
    //x[n-1] = y[n-1]/d[n-1];
    x[n-1] = 0.0;

    //Backward substitution with ytilde and dtilde, and writing to file.
    for(int i = n-2; i > 0; i--){

        x[i] = (y[i] - e[i]*(x[i+1]))/d[i];
        myfile << x[i] << "\n";

    }//end for

    //closing myfile
    myfile.close();

return 0;

}
