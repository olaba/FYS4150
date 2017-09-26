//Jacobi algorithm, using max values.
#include<armadillo>
#include<project2_header.h>
#include<iostream>
using namespace arma;
using namespace std;


mat jacobi_max(mat A){

//Define tolerance, pointers for biggest entry, and norm
double eps = 10^-8;
int *k;
int *l;
double off_norm = (norm(A,'fro'))^2 - ;

while ( eps > off_norm ){

        //Compute Tau --> t --> c --> s

        //Update S and Stranspose.

        //Execute transformation with the found values of c and s

        //Find new biggest placement.


}; //end while

}// end function
