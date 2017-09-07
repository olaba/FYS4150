#include "project1_header.h"
#include <armadillo>

using namespace arma;
using namespace std;


int main() {

   //number of grid points n.
   int n[3] = {10,100,1000};

   //runs the algorithms for all n
   for(int i = 0; i < 3; i++){

       tridiagonal(n[i]);
       topliz(n[i]);
       exact(n[i]);
       logerr(n[i]);

   }//end for


   return 0;

}
