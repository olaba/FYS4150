#include "project1_header.h"

using namespace std;

int main(int argc, char *argv[]) {

//runs the algorithms for all n
for(int i = 1; i < (argc+1); i++){

       tridiagonal(atoi(argv[i]));
       topliz(atoi(argv[i]));
       //exact(atoi(argv[i]));
       //logerr(atoi(argv[i]));

}//end for
return 0;
}
