//A function where we compute the linear eq with LU code given at website
#include<iostream>
#include<math.h>
#include<fstream>
#include "armadillo"

using namespace std;
using namespace arma;


void lud(int n){

    ofstream myfile;
    if(n == 10){myfile.open("results_lud_10n.txt");}
    if(n == 100){myfile.open("results_lud_100n.txt");}
    if(n == 1000){myfile.open("results_lud_1000n.txt");}
    if(n == 1000000){myfile.open("results_lud_10e6n.txt");}


    //Initializing vectors with -1's and 2's and length n-1 and n for the diagonals
    vec v1(n-1);
    v1.fill(-1.0);
    vec v2(n);
    v2.fill(2.0);

    //Making three matrices with one diagonal each
    mat m1 = diagmat(v1, -1);
    mat m2 = diagmat(v2, 0);
    mat m3 = diagmat(v1, 1);

    //Adding together the three matrices to get our tridiagonal matrix
    mat m = m1 + m2 + m3;





    //Initializing forcing term vector and steplength h
    vec y(n);
    double h = (1.0/(n+1));

    for(int i = 0 ; i < n; i++){

         y[i] = h*h*(100*exp(-10*(h*(i))));

    }//end for

    //Decleare start and stop time.
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    // Start time ------------------------------------------------
    start = std::chrono::high_resolution_clock::now();


    //Solving with solve
    vec x = solve(m,y);

    //Stop time --------------------------------------------
    end = std::chrono::high_resolution_clock::now();
    cout << "lud used: " <<(double) chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanoseconds for n = " << n << "\n";


    //writing results to file
    for(int i = 0; i < (n); i++){

        myfile << x[i] << "\n";

    }//end for

    //closing file
    myfile.close();



    //mat L, U;
    //lu(L, U, m);
}
