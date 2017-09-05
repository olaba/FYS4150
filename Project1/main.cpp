#include "project1_header.h"
using namespace std;


int main() {

   //number of mesh points n.
   int n[3] = {10,100,1000};

   for(int i = 0; i < 3; i++){

       tridiagonal(n[i]);
       topliz(n[i]);
       exact(n[i]);
       //logerr(i);
       //lu(i);

   }//end for


   return 0;

}
