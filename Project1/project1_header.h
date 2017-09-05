#ifndef PROJECT1_HEADER_H
#define PROJECT1_HEADER_H

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

//initialize a function that solves a general tridiagonal matrix.
void tridiagonal(int n);

//initialize a function that solves the töpliz matrix.
void topliz(int n);

//initialize a function that computes exact values for the problem
void exact(int n);

//initialize a function that finds the relative error.
void logerr(int n);

//initialize a function to do all the LU stuff.
void LU(int n);

#endif // PROJECT1_HEADER_H

