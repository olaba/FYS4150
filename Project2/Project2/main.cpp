#include "project2_header.h"
using namespace std;
using namespace arma;
int main()
{

    //Initialize size, rho, matrix for one electron case
    double rho = 100;
    int N = 10;
    mat Ola = mat_generate_one(N, rho);
    mat Olato = mat_generate_one(N, rho);

    //Do the jacobi rotation max algo and take out the eigenvalues
    mat Ingvild = jacobi_max(Ola);
    vec our_eigenvalues_maxalgo = Ingvild.diag();

    //Do the jacobi rotation cyclic algo and take out the eigenvalues
    mat Hanne = jacobi_cyclic(Olato);
    vec our_eigenvalues_cyclicalgo = Hanne.diag();

    //initiates eigenvector matrix and eigenvaluecolumn for the eig_sym function
    Col<double> armeigenval;
    mat armeigenvec;

    //Time the pre-built armadillo eig_sym function
        //Decleare start and stop time.
       std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
       // Start time ------------------------------------------------
       start = std::chrono::high_resolution_clock::now();

       //Armadillo function for finding eigenvalues
       eig_sym(armeigenval,armeigenvec,Ola);


       //Stop time --------------------------------------------
       end = std::chrono::high_resolution_clock::now();
       cout << "Armadillo function used: " <<(double) chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanoseconds for n = " << (N-2) << "\n";




    cout << "eigenvalues from maxalgo: " << endl << our_eigenvalues_maxalgo << endl;
    cout << "eigenvalues from cyclicalgo: "<< endl << our_eigenvalues_cyclicalgo << endl;
    cout << "eigenvalues from armadillo function: " << endl << armeigenval << endl;
}
