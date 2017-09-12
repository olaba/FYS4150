#include "project1_header.h"
#include "time.h"
using namespace std;


int main(int argc, char *argv[]) {

//runs the algorithms for all n
for(int i = 1; i < (argc); i++){

       tridiagonal(atoi(argv[i]));
       topliz(atoi(argv[i]));
<<<<<<< HEAD
       exact(atoi(argv[i]));
       logerr(atoi(argv[i]));
       lud(atoi(argv[i]));
=======
       //exact(atoi(argv[i]));
       //logerr(atoi(argv[i]));
>>>>>>> 7e00fd668a1b2e787db4a30de02a90d4de06b78a

}//end for
return 0;
}
