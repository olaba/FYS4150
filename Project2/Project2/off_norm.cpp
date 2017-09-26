//Finds the updated offdiagonal norm
#include<armadillo>
#include<project2_header.h>
#include<iostream>
using namespace arma;
using namespace std;

double off_norm(mat A){

    //declearing a variable for "diagonal norm".
    double diagnorm;

    //forloop over size of matrix
    for(int i = 0; i < n; i++){

        //calc. the sum of the sqare of diagonal entries
        diagnorm += A(i,i)^2;

    }//end for

    //calculates the off_norm value and returns it
    double off_norm_val = sqrt(norm(A,'fro')^2 - diagnorm);
    return off_norm_val;

}
