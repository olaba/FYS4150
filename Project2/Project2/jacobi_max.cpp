//Jacobi max algorithm

#include <iostream>
#include "armadillo"

using namespace arma;
using namespace std;


//Define tolerance

double eps = 10^(-8);

cout << eps;

//While eps > off(A)

        //Find max in A (costs O(n^2) flops)

        //Compute Tau --> t --> c --> s

        //Update S and Stranspose.

        //Execute transformation with the found values of c and s

        // if yes --> you're done!
        // if no --> new loops from new max
