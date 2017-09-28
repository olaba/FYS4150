#include "project2_header.h"

using namespace arma;
using namespace std;

int main()
{

    mat A = randu<mat>(4,4);
    mat B = jacobi_max(A);
    cout << B << endl;


}
