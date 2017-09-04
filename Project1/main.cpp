#include "project1_header.h"
using namespace std;


int main() {

   int n = 10;

   double a = 0.0;
   double b = 0.0;

   a = tridiagonal(n);
   b = topliz(n);
   c = logerr(n);

   return 0;

}
