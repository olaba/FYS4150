//Calculates the maximum off diagonal
//To use later in the jacobi algorithms
#include<armadillo>
#include<project2_header.h>
#include<iostream>
using namespace arma;
using namespace std;

vec max_off(mat A){

    //Declearing n, max value and a vector for indexes.
    int n = A.n_rows;
    double max = 0.0;
    int k;
    int l;


    for(int i = 0; i < n; i++){ //Rows
                for(int j = 0; j < n; j++ ){ //Col

                    if (i != j){
                       //Overwrites max, and saves indexes if bigger
                       double aij = fabs(A(i,j));
                       if (aij > max){

                            max = Aij;
                            k = i;
                            l = j;
                                }
                       }

            }//end for j
        }// end for i

}
