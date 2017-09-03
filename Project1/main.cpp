#include <iostream>
#include <math.h>
#include <fstream>
#include <project1_header.h>

using namespace std;

int main()
{
int n = 10;

//General tridiagonal algorithm
double a = tridiagonal(n);

//Topliz algorithm
double b = topliz(n);


return a;

}
