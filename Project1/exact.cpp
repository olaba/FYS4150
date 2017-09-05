//Calculates the exact answer, and writes this to file
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void exact(int n){


//initialize and opening file
std::ofstream myfile;
if(n == 10){myfile.open("results_exact_10n.txt");}
if(n == 100){myfile.open("results_exact_100n.txt");}
if(n == 1000){myfile.open("results_exact_1000n.txt");}
//if(n == 10000000){myfile.open("results_exact_10e7n.txt");} crashes code :(

//declearing steplength vector
double h = (1.0/(n+1)); //steplength

//Writing exact answer to file.
for(int i = 1; i < (n+1); i++){

    myfile << 1 - (1-exp(-10))*h*i - exp(-10*h*i) << "\n" ;

}//end for


myfile.close();

}
