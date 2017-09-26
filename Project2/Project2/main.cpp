#include <iostream>
#include "project2_header.h"
using namespace std;
using namespace arma;

int main(){
//Define matrix for one electron
mat A = randu<mat>(4,4);

double svar = off_norm(A);

cout << svar;
//run jacobi_max

//run jacobi_cyclic

//run armadillo function

//run householder

//run eigenvaluefunction on results from householder!

//Time everything
//Implement unit tests!
//Write to file
//Plot the function?
cout << A << endl;
return 0;

}
