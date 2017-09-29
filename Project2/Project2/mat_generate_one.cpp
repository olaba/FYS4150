#include "project2_header.h"
using namespace std;
using namespace arma;

mat mat_generate_one(int N, double rho_max){


    //define stepsize h
    double h = rho_max/N;

    //initializing "schrödinger" matrix. Endpoints not included
    mat A;
    A.zeros(N-2,N-2);

    //Inserting values in main diagonal, upper and lower diagonal
    for(int i=0; i<(N-2); i++){

        //diagonal
        A(i,i) = (2/pow(h, 2)) + pow((i+1)*h, 2);

        //upper and lower diagonal
        if(i<(N-1)){
            A(i+1,i)=-1/pow(h,2);
            A(i, i+1)=-1/pow(h,2);

        }//end if

    }//end for

return A;
}//end function
