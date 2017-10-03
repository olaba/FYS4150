#include "project2_header.h"
using namespace std;
using namespace arma;

mat mat_generate(int N, double rho_max, bool one_electron){

    //define stepsize h and omega (from paper).
    double h = rho_max/N;
    double omega = 5;

    //initializing "schrödinger" matrix. Endpoints not included
    mat A;
    A.zeros((N-2),(N-2));

    //Inserting values in main diagonal, upper and lower diagonal
    for(int i=0; i<(N-2); i++){


        if(one_electron){

            //Diagonal if one electron
            A(i,i) = (2/(h*h)) + (i+1)*h*h*(i+1);

        }//end if

        else{

            // New diagonal if two electrons(interacting case)
            A(i,i) = (2/pow(h, 2)) + omega*omega*pow((i+1)*h, 2) + 1/((i+1)*h);

        }//end else

        //upper and lower diagonal
        if(i<(N-3)){

            A(i+1,i) = -1/(h*h);
            A(i, i+1) = -1/(h*h);

        }//end if

    }//end for

return A;
}//end function
