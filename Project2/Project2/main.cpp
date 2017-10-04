#include "project2_header.h"
using namespace std;
using namespace arma;
int main()
{

    //Initialize size, rho, matrix for one electron case
    double rho = 7.9;
    int N = 200;
    mat Ola = mat_generate(N, rho, true);

    //Do the jacobi rotation max algo and take out the eigenvalues
    mat Ingvild = jacobi_max(Ola);
    vec our_eigenvalues_maxalgo = Ingvild.diag();
    //vec our_sorted_eigenvalues_maxalgo = sort(our_eigenvalues_maxalgo);

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
       cout << "Armadillo function used: " <<(double) chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanoseconds for n = " << N << "\n";

       vec sort_armeigenval = sort(armeigenval);
       vec sort_our_eigenvalues_maxalgo = sort(our_eigenvalues_maxalgo);


     //Printing rho
     cout << "rho_max is set to rho="<< rho << endl;
    //Prints out the eigenvalue results
    cout <<" eigenvalues from maxalgo: " << endl << sort_our_eigenvalues_maxalgo << endl;
    cout <<"eigenvalues from armadillo function: " << endl << sort_armeigenval << endl;

}

