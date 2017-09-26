#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H
#include<math.h>
#include<armadillo>
using namespace arma;

//Jacobi max
mat jacobi_max(mat A);

//Jacobi cyclic
mat jacobi_cyclic(mat A);

//householders algorithm
mat householder(mat A);

//Function to find max off-diagonal entry
vec max_off(mat A);


#endif // PROJECT2_HEADER_H
