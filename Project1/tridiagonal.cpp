//Tridiagonal function
namespace std

double tridiagonal(int n) {

//initialize and opening file
std::ofstream myfile;
myfile.open("results.txt");

//initialize vector d and e1, e2 of a general tridiagonal matrix
double e1[n]; //upper diagonal
double d[n]; //mid diagonal
double e2[n]; //lower diagonal
double y[n]; //forcing term f(x)
double x[n] = {0.0}; //Our numerical results
double ex[n] = {0.0}; //The exact solution
double h = (1.0/(n-1)); //steplength

//Declearing the töpliz matrix values and forcing term.
for(int i = 0; i < n; i++){e1[i] = 1.0; e2[i] = 1.0; d[i] = -2.0; y[i] = h*h*(100*exp(-10*(h*i)));}

//Declearing the exact answer vector and writing to file.
for(int i = 0; i < n; i++){

    ex[i] = 1 - (1-exp(-10))*h*i - exp(-10*h*i);
    myfile << ex[i] << "\n" ;

}//end for

//Forward substitution algorithm
for(int i = 0; i < n; i++){

     //declearing dtilde
     d[i+1] = d[i+1] - (e1[i+1]*e2[i])/d[i];

     //declearing ytilde
     y[i+1] = y[i+1] - ((e1[i+1])*(y[i]))/d[i];

}//end for

//first entry of backwardsubstitution
//x[n-1] = y[n-1]/d[n-1];
x[n-1] = 0.0;

//Backward substitution with ytilde and dtilde, and writing to file.
for(int i = n-2; i > 0; i--){

    x[i] = (y[i] - e2[i]*(x[i+1]))/d[i];
    myfile << x[i] << "\n";

}//end for

//closing myfile
myfile.close();

return 0.0;

}
