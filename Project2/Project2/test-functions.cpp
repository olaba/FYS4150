/*
//Unit test of code performed by catch
#include "catch.hpp"
#include "project2_header.h"
using namespace std;
using namespace arma;


//Testing off max
TEST_CASE ( "Find the max off diagonal entry of a matrix", "[offmax]"){


    //Defining matrixes with well known offnorms, maximum value entries and eigenvalues.
    mat A {eye(5,5)};
    mat B {eye(5,5)};
    mat C {zeros(5,5)};


    B(1,5) = 8.0;
    C(2,4) = 9.0;
    B(2,3) = 7.9;
    C(1,2) = 9.1;


    //Defining the indicies for max off norm entry.
    int B_k;
    int B_r;
    int C_k;
    int C_r;

    //Running the off_max function to update values of A/B/C_k/r.
    off_max(B, &B_r, &B_k);
    off_max(C, &C_r, &C_k);


    REQUIRE( B_r == 5);
    REQUIRE( B_k == 1);
    REQUIRE( C_r == 2);
    REQUIRE( C_k == 1);
}

/*
//Testing off norm
TEST_CASE ( "Find the offdiagonal norm of a matrix", "[offnorm]"){
    REQUIRE( (off_norm(A)) == 0);
    REQUIRE( (off_norm()) == 16);
    REQUIRE( (off_norm()) == 25);
}

//testing Jacobi_max, assuming armadillofunction is correct.
TEST_CASE ( "Find the eigenvalues of a matrix by jacobi_max algorithm", "[jacobimax]"){
    REQUIRE( (jacobi_cyclic(A)) == 0);
    REQUIRE( (jacobi_cyclic(B)) == 16);
    REQUIRE( (jacobi_cyclic(B)) == 25);
}

//testing Jacobi_cyclic, assuming armadillofunction is correct.
TEST_CASE ( "Find the eigenvalues of a matrix by jacobi_cyclic algorithm", "[jacobicyclic]"){
    REQUIRE( (jacobi_cyclic(A)) == 0);
    REQUIRE( (jacobi_cyclic(B)) == 16);
    REQUIRE( (jacobi_cyclic(B)) == 25);
}
*/
