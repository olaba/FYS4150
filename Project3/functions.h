#ifndef functions_H
#define functions_H
#include <vector>
#include "planet.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using std::vector;

// A class with functions used to solve project3 by generating "multiple body systems".
// And solving them with the verletvelocity algorithm
// The VerletV functions are quite general except the write to file system.

class functions
{

//setting planet as friend class
friend class planet;

public:

    //initializers
    functions();
    functions(double r);


    // properties
    int n_planets;
    double radius, mass_tot, G, mass_sun;
    vector<planet> planets;



    //General functions
    void add(planet newplanet);
    void GravitationalForce(planet &current, planet &other, double &Fx, double &Fy);


    //Verlet solver for different systems
    void Verlet(double total_time, int N);

    //Stripped down version of VerletV to run for as many stepnumbers as needed in opg 3g)
    void VerletVMercur(double total_time, int N);




};

#endif // functions_H
