//Jacobi max algorithm
#include "project2_header.h"


mat jacobi_max(mat A){


//Defining tolerance
double eps = pow(10, -8);

//Calculating norm of offdiagonal entries of A
double off_norm_value = off_norm(A);

//initializing indices for maximum off diagonal entry
int max_row, max_col;
int N = A.n_cols;

//initializing the eigenvector
mat x = eye<mat>(N,N);


while(eps < off_norm_value){


    //Finding and assigning indices of maximum value
    off_max(A, &max_row, &max_col);

    // Computing tau, tangens, cos and sin for the angle making A(max)=0
    double tau = (A(max_col, max_col)-A(max_row,max_row))/(2*A(max_row, max_col));
    double t = -tau - sqrt(1+pow(tau,2));
    double c = 1/(sqrt(1+pow(t,2)));
    double s = t*c;

    //Declearing temp. values for flipping/rotating procedure
    double a_cc, a_rr, a_ic, a_ir, x_ic, x_ir;

    //rotating A, first the diagonals
    a_cc = A(max_col,max_col);
    a_rr = A(max_row,max_row);
    A(max_col,max_col) = c*c*a_cc - 2.0*c*s*A(max_col,max_row) + s*s*a_rr;
    A(max_row,max_row) = s*s*a_cc + 2.0*c*s*A(max_col,max_row) + c*c*a_rr;
    A(max_row,max_col) = 0.0; //så har me juksa litt
    A(max_col,max_row) = 0.0; //her også

    //then the offdiagonals
    for(int i = 0; i < N; i++){

        //if that stops the diagonals from flipping again.
        if( i != max_col && i != max_row){

            a_ir = A(i,max_row);
            a_ic = A(i,max_col);
            A(i,max_col) = c*a_ic - s*a_ir;
            A(max_col,i) = A(i,max_col);
            A(i,max_row) = c*a_ir + s*a_ic;
            A(max_row,i) = A(i,max_row);

        }//end if

        //Lastly updates the eigenvector
        x_ic = x(i,max_col);
        x_ir = x(i,max_row);
        x(i,max_col) = c*x_ic - s*x_ir;
        x(i,max_row) = c*x_ir - s*x_ic;

    }//end for

//recalculates the offnorm of A
off_norm_value = off_norm(A);

}//end while

//returns
return A;


}//end function




