//Calculates the maximum off diagonal
//To use later in the jacobi algorithms
#include<project2_header.h>
using namespace arma;
using namespace std;

void max_off(mat A, int *max_r, int *max_c){

    //Declearing n, max value
    int n = A.n_rows;
    double max = 0.0;

    //Two for loops over upper tridiagonal, since A remains
    //symmetric even after rotation.
    for(int i = 0; i < n; i++){ //Rows
                for(int j = (i+1); j < n; j++ ){ //Col

                       //Overwrites max, and saves indexes if bigger
                       double aij = fabs(A(i,j));
                       if (aij > max){

                            max = aij;
                            max_r = i;
                            max_c = j;

                            } //end if

            }//end for j
        }// end for i

}//end function
