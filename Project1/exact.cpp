//Calculates the exact answer, and writes to file
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void exact(int n){

//declearing file and vectors
    //initialize and opening file
    std::ofstream myfile;
    if(n == 10){myfile.open("results_exact_10n.txt");}
    if(n == 100){myfile.open("results_exact_100n.txt");}
    if(n == 1000){myfile.open("results_exact_1000n.txt");}

//declearing steplength vector
double h = (1.0/(n+1)); //steplength

//Writing to file.
for(int i = 1; i < (n+1); i++){

    myfile << 1 - (1-exp(-10))*h*i - exp(-10*h*i) << "\n" ; //dont write the last 0 to file

}//end for

myfile.close();

}
