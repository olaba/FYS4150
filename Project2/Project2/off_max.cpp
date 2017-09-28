#include"project2_header.h"

using namespace arma;
using namespace std;

void off_max(mat A, int *max_r, int *max_c){

    //Declaring n and max value
    int n = A.n_rows;
    double max = 0.0;

    //Two loops going through upper matrix, searching for max value
    for(int i = 0; i < n; i++){
        for(int j = (i+1); j < n; j++){

            double aij=fabs(A(i,j));
            if(aij > max){
                max = aij;
                *max_r = i;
                *max_c = j;
            }//end if
        } //end for j
    }//end for i

}//end function
