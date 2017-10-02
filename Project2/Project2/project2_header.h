#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H

#include <iostream>
#include "armadillo"
#include <math.h>
#include <chrono>


using namespace arma;

//Jacobi max
mat jacobi_max(mat A);

//off_norm
double off_norm(mat A);

//Jacobi cyclic
mat jacobi_cyclic(mat A);

//One electron matrix generator
mat mat_generate(int N, double rho_max, bool one_electron);

//Offdiagonal max-finder
void off_max(mat A, int *max_r, int *max_c);


//householders algorithm



#endif // PROJECT2_HEADER_H
