//Finds the updated offdiagonal norm

#include"project2_header.h"


using namespace arma;
using namespace std;

double off_norm(mat A){

    //declearing a variable for "diagonal norm".
    double diagnorm = 0;
    int N = A.n_rows;


    //forloop over size of matrix
    for(int i = 0; i < N; i++){

        //calc. the sum of the sqare of diagonal entries
        diagnorm += A(i,i)*A(i,i);

    }//end for

    //calculates the off_norm value and returns it

    double off_norm_val = sqrt(pow(norm(A, "fro"), 2) - diagnorm);

    return off_norm_val;

}
