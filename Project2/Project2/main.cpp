#include "project2_header.h"
using namespace std;
using namespace arma;
int main()
{

    mat A = randu<mat>(4,4);
    mat D = randu<mat>(4,4);
    cout << A << endl;
    cout << D << endl;
    mat B = jacobi_max(A);
    mat C = jacobi_cyclic(D);
    cout << B << endl;
    cout << C << endl;

}
