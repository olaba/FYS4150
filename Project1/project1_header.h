#ifndef PROJECT1_HEADER_H
#define PROJECT1_HEADER_H

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

//initialize a function that solves a general tridiagonal matrix.
double tridiagonal(int n);

//initialize a function that solves the töpliz matrix.
double topliz(int n);

//initialize a function that finds the relative error.
double logerr(double ex, double x);

//initialize a function to do all the LU stuff.
double LU();

#endif // PROJECT1_HEADER_H

