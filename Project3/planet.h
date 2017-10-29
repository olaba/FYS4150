#ifndef PLANET_H
#define PLANET_H
#include <cmath>
#include <vector>
using std::vector;

//A class used for planets in project 3.
//By adding radiusFromSun and PotentialEnergySun functions, we can run the solver without actually adding the sun itself.
//#blackmagic

class planet
{
public:

    //Planet Values
    double mass;
    double vel[2]; //x and y velocity
    double pos[2]; //x and y position
    double potential;
    double kinetic;

    //Initializers
    planet();
    planet(double M, double x, double y, double vx, double vy);

    //Functions
    double distance(planet otherPlanet);
    double distance_x(planet otherPlanet);
    double distance_y(planet otherPlanet);
    double GravitationalForce(planet otherPlanet, double G);
    double Acceleration(planet otherPlanet, double G);
    double KineticEnergy();
    double PotentialEnergy(planet &otherPlanet, double G, double Eps);
    double PotentialEnergySun();
    double AngularMom();
    double radiusFromSun();

};

#endif // PLANET_H
