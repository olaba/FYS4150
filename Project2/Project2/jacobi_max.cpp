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

//Define rotation matrix S
mat S = eye<mat>(N,N);
mat Stemp = eye<mat>(N,N);

while(eps < off_norm_value){


    //Finding and assigning indices of maximum value
    off_max(A, &max_row, &max_col);

    // Computing tau, tangens, cos and sin for the angle making A(max)=0
    double tau = (A(max_col, max_col)-A(max_row,max_row))/(2*A(max_row, max_col));
    double t = -tau - sqrt(1+pow(tau,2));
    double c = 1/(sqrt(1+pow(t,2)));
    double s = t*c;




    //Rotating A
    Stemp = S*A;
    A = Stemp*S.t();


}//end while

return A;


}//end function




