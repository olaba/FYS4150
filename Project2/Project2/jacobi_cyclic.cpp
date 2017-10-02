//Cyclic jacobi algorithm
// i = row, j = column
#include "project2_header.h"
using namespace std;
using namespace arma;

mat jacobi_cyclic(mat D){


//initializing dimention N and eigenvectormatrix x
int N = D.n_cols;
mat x = eye<mat>(N,N);

//Defining tolerance
double eps = pow(10, -8);

//Calculating norm of offdiagonal entries of D
double off_norm_value = off_norm(D);


//Decleare start and stop time.
   std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
   // Start time ------------------------------------------------
   start = std::chrono::high_resolution_clock::now();


while(off_norm_value > eps){
  for(int i = 0; i < N; i++){
      for(int j=(i+1); j < N; j++){


          // Computing tau, tangens, cos and sin for the angle making D(i,j)=D(j,i)=0
          //HER MÅ VI HA EN IF så vi unngår nan nan nan!
          double tau = (D(j, j)-D(i,i))/(2*D(i, j));
          double t = -tau - sqrt(1+pow(tau,2));
          double c = 1/(sqrt(1+pow(t,2)));
          double s = t*c;


          //Declearing temp. values for flipping/rotating procedure
          double a_cc, a_rr, a_kc, a_kr, x_kc, x_kr;

          //rotating A, first the diagonals
          a_cc = D(j,j);
          a_rr = D(i,i);
          D(j,j) = c*c*a_cc - 2.0*c*s*D(j,i) + s*s*a_rr;
          D(i,i) = s*s*a_cc + 2.0*c*s*D(j,j) + c*c*a_rr;
          D(i,j) = 0.0;
          D(j,i) = 0.0;


          //then the offdiagonals
              for(int k = 0; k < N; k++){

                  //if that stops the diagonals from flipping again.
                  if( k != j && k != i){

                      a_kr = D(k,i);
                      a_kc = D(k,j);
                      D(k,j) = c*a_kc - s*a_kr;
                      D(j,k) = D(k,j);
                      D(k,i) = c*a_kr + s*a_kc;
                      D(i,k) = D(k,i);

                  }//end if

                  //Lastly updates the eigenvector
                  x_kc = x(k,j);
                  x_kr = x(k,i);
                  x(k,j) = c*x_kc - s*x_kr;
                  x(k,i) = c*x_kr - s*x_kc;

              }//end for

        }//end for j

    }//end for i

    off_norm_value = off_norm(D);

}//end while

//Stop time --------------------------------------------
end = std::chrono::high_resolution_clock::now();
cout << "Jacobi_cyclic used: " <<(double) chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanoseconds for n = " << N << "\n";


return D;


}//end function
