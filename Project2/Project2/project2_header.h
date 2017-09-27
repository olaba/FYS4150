#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H
#include <math.h>
#include <iostream>
#include "armadillo"
using namespace arma;
using namespace std;

//Jacobi max
mat jacobi_max(mat A);

//Jacobi cyclic
mat jacobi_cyclic(mat A);

//householders algorithm
mat householder(mat A);

//Function to find max off-diagonal entry
void off_max(mat A, int *a, int *b);

//Off norm function
double off_norm(mat A);


#endif // PROJECT2_HEADER_H
