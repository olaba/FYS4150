#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H

#include <iostream>
#include "armadillo"
#include <math.h>


using namespace arma;

//Jacobi max


mat jacobi_max(mat A);

//off_norm

double off_norm(mat A);

//Jacobi cyclic

mat jacobi_cyclic(mat A);

void off_max(mat A, int *max_r, int *max_c);


//householders algorithm



#endif // PROJECT2_HEADER_H
