#include "project2_header.h"
using namespace std;
using namespace arma;
int main()
{
    double rho = 100;
    int N = 10;
    mat Ola = mat_generate_one(N, rho);
    mat Ingvild = jacobi_max(Ola);
    vec oureigenvalues = Ingvild.diag();

    Col<double> armeigenval;
    mat armeigenvec;
    eig_sym(armeigenval,armeigenvec,Ola);

    cout << oureigenvalues <<endl;
    cout << armeigenval <<endl;
}
