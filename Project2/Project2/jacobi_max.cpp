//Jacobi algorithm, using max values.
#include<armadillo>
#include<project2_header.h>
#include<iostream>
using namespace arma;
using namespace std;


mat jacobi_max(mat A){

//Define tolerance, norm, and row/col pointers for biggest entry.
double eps = pow(10,-8);
double off_norm_val = off_norm(A);
int max_row;
int max_col;
int N = A.n_rows;

//Define rotation matrix S
mat S = eye<mat>(N,N);
mat Stemp = eye<mat>(N,N);

//While loop based on offnorm tolerance.
while (eps < off_norm_val){

        //Finds biggest off diagonal entry
        off_max(A, &max_row, &max_col);

        //Compute Tau --> tangens --> cosinus --> sinus
        double tau = (A(max_col,max_col)-A(max_row,max_row))/(2*(A(max_row,max_col)));
        double t = - tau - sqrt(1 + pow(tau,2));
        double c = 1/(sqrt(1 + pow(t,2)));

        //Update A
        Stemp = S*A;
        A = Stemp*S.t();

        //Execute transformation with the found values of c and s


        //Find new off norm




}; //end while

}// end function
