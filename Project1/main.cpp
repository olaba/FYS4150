#include "project1_header.h"
<<<<<<< HEAD
#include <armadillo>

using namespace arma;
=======
#include "time.h"
>>>>>>> Project2
using namespace std;


int main(int argc, char *argv[]) {

//runs the algorithms for all n
for(int i = 1; i < (argc); i++){

       //tridiagonal(atoi(argv[i]));
       //topliz(atoi(argv[i]));
       //exact(atoi(argv[i]));
       //logerr(atoi(argv[i]));
       lud(atoi(argv[i]));

}//end for
return 0;
}
