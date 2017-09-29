//Cyclic jacobi algorithm
// i = row, j = column
#include "project2_header.h"
using namespace std;
using namespace arma;

mat jacobi_cyclic(mat A){


//initializing dimention N and eigenvectormatrix x
int N = A.n_cols;
mat x = eye<mat>(N,N);

//Defining tolerance
double eps = pow(10, -8);

//Calculating norm of offdiagonal entries of A
double off_norm_value = off_norm(A);

while(off_norm_value > eps){
  for(int i = 0; i < N; i++){
      for(int j=(i+1); j < N; j++){


          // Computing tau, tangens, cos and sin for the angle making A(i,j)=A(j,i)=0
          double tau = (A(j, j)-A(i,i))/(2*A(i, j));
          double t = -tau - sqrt(1+pow(tau,2));
          double c = 1/(sqrt(1+pow(t,2)));
          double s = t*c;



          //Declearing temp. values for flipping/rotating procedure
          double a_cc, a_rr, a_ic, a_ir, x_ic, x_ir;

          //rotating A, first the diagonals
          a_cc = A(j,j);
          a_rr = A(i,i);
          A(j,j) = c*c*a_cc - 2.0*c*s*A(j,i) + s*s*a_rr;
          A(i,i) = s*s*a_cc + 2.0*c*s*A(j,j) + c*c*a_rr;
          A(i,j) = 0.0;
          A(j,i) = 0.0;




        }//end for i

    }//end for j


}//end while




}//end function
