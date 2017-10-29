#include "planet.h"

// Empty initializer
planet::planet()
{
    mass = 1.;
    pos[0] = 1.;
    pos[1] = 0.;
    vel[0] = 0.;
    vel[1] = 2*3.14;
    potential = 0.;
    kinetic = 0.;
}

//Initializing with values
planet::planet(double M, double x, double y, double vx, double vy)
{
    mass = M;
    pos[0] = x;
    pos[1] = y;
    vel[0] = vx;
    vel[1] = vy;
    potential = 0;
    kinetic = 0;
}

//Calculating distance to other planet
double planet::distance(planet otherPlanet)
{
    double x1, y1, x2, y2, xx, yy, dist;

    x1 = this->pos[0];
    x2 = otherPlanet.pos[0];

    y1 = this->pos[1];
    y2 = otherPlanet.pos[1];

    xx = x1-x2;
    yy = y1-y2;

    dist = sqrt(xx*xx + yy*yy);

    return dist;
}

//Calculating x-component of distance to other planet
double planet::distance_x(planet otherPlanet)
{
    double x = this->pos[0]-otherPlanet.pos[0];

    return x;
}

//Calculating y-component of distance to other planet
double planet::distance_y(planet otherPlanet)
{
    double y = this->pos[1]-otherPlanet.pos[1];

    return y;
}


//Calculating gravitational force (from Newtons laws)
double planet::GravitationalForce(planet otherPlanet, double G)
{
    double r = this->distance(otherPlanet);

    //Returning 0 if distance between planets = 0
    if(r == 0){return 0;}

    //Calculates the gravitational force
    else{
        double F = G*this->mass*otherPlanet.mass/(r*r);
        return F;
    }
}// end GravitationalForce


//Calculating acceleration from Gravitational force
double planet::Acceleration(planet otherPlanet, double G)
{
 double r = this->distance(otherPlanet);

    //Returning 0 if distance between planets is zero
    if(r == 0){return 0;}

    //Calculates the acceleration
    else{
        double a = this->GravitationalForce(otherPlanet, G)/(this->mass*r);
        return a;
        }
}//end Acceleration

//Calculating the radius from the sun in the solar system
double planet::radiusFromSun(){

    return sqrt(pos[0]*pos[0] + pos[1]*pos[1]);
}

//Calculating kinetic energy of a planet
double planet::KineticEnergy()
{
    double velocity2 = (this->vel[0]*this->vel[0]) + (this->vel[1]*this->vel[1]);
    return 0.5*this->mass*velocity2;
}

//Calculating Potential energy between sun and the planet
double planet::PotentialEnergySun(){

    return 4*M_PI*M_PI*this->mass/(this->radiusFromSun());


}

//Calculating Angular momentum of the planet
double planet::AngularMom(){

        return (2*M_PI*pow(2,(this->radiusFromSun()))*(this->mass))/(sqrt(this->vel[0]*this->vel[0]) + (this->vel[1]*this->vel[1]));

}




