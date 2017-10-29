#include "functions.h"
#include <cmath>
#include "planet.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

functions::functions()
{

    //Initial values without specification
    n_planets = 0;
    radius = 1;
    mass_tot = 0;
    G = 4*M_PI*M_PI;
    mass_sun = 1.989*pow(10,30);

}

functions::functions(double r){

    //Initial values with specification for radius
    n_planets = 0;
    radius = r;
    //mass_tot = 0; only for moons/galaxy
    G = 4*M_PI*M_PI;

}

//Function that adds planet
void functions::add(planet newplanet){

    n_planets += 1;
    planets.push_back(newplanet);
}

//Implementing function that calculates gravitational force excerted on planet 'current' from 'other'
void functions::GravitationalForce(planet &current, planet &other, double &Fx, double &Fy){


        //Using planet-memberfunctions to get distances between planets 'current' and 'other'
        double x = current.distance_x(other);
        double y = current.distance_y(other);
        double r = current.distance(other);

        //Calculating product of the masses
        double M_m = current.mass*other.mass;

        //Calculating the components of the gravity force between 'current' and 'other'.
        //The way we have defined the distance requires negative force => -=.
        Fx -= this->G*M_m*x/(pow(r,3)*mass_sun);
        Fy -= this->G*M_m*y/(pow(r,3)*mass_sun);

}



void functions::Verlet(double total_time, int N)
{
        //Define time step
        double dt = total_time/((double) N);

        //initialize time
        double time = 0.0;

        //initialize kinetic, potential and angular momentum
        double kinetic, potential, angular;

        //Initializing files
        std::ofstream myfile;
        myfile.open ("VerletValuesEarth.txt");
        std::ofstream myfile2;
        myfile2.open("ConservedVerletValues.txt");
        //Initializing files
        std::ofstream myfile3;
        myfile3.open ("VerletValuesJupiter.txt");
        std::ofstream myfile4;
        myfile4.open("VerletValuesMars.txt");
        std::ofstream myfile5;
        myfile5.open("VerletValuesSaturn.txt");
        std::ofstream myfile6;
        myfile6.open("VerletValuesUranus.txt");
        std::ofstream myfile7;
        myfile7.open("VerletValuesMercury.txt");
        std::ofstream myfile8;
        myfile8.open("VerletValuesNeptune.txt");
        std::ofstream myfile9;
        myfile9.open("VerletValuesVenus.txt");



        //Initializing acceleration and force-components
        double a_x, a_y,a_x_new,a_y_new,Fx,Fy,Fxnew,Fynew;

        //starting while-loop that goes until total_time is reached
        while(time < total_time){

            //Setting energies, ang.mom to zero for this timestep
            kinetic = potential = angular = 0;

            //starting for-loop deciding 'current planet' from 'planets[i]'
            for(int cp = 0; cp < n_planets; cp++){

                //Create pointer that points to the right element in 'planets'
                planet &current = planets[cp];

                //zero acceleration, and forces before calculations for this round's 'current'
                Fx = Fy = Fxnew = Fynew = 0;

                //Starting for-loop that calculate sum of forces exerted on this round's 'current' from the other planets
                for(int op = 0; op < n_planets; op++){

                    //create pointer that points to element in 'planets'
                    planet &other = planets[op];

                    //starting if that leaves out calculation when 'other' == 'current'
                    if(op != cp){

                        GravitationalForce(current, other, Fx, Fy);

                    }//end if

                }//end for(other planets)

                //Calculate acceleration at current position from forces
                double r = current.radiusFromSun();
                a_x = -(G/(pow(r,3)))*current.pos[0] + Fx/current.mass;
                a_y = -(G/(pow(r,3)))*current.pos[1] + Fy/current.mass;

                //calculate new position for 'current' from acceleration, based on Verlet Velocity algorithm
                current.pos[0] += current.vel[0]*dt + 0.5*dt*dt*a_x;
                current.pos[1] += current.vel[1]*dt + 0.5*dt*dt*a_y;

                //Starting for-loop that calculates "new" forces on 'current' in new position
                for(int op = 0; op < n_planets; op++){

                    //create pointer that points to element in 'planets'
                    planet &other = planets[op];


                    //starting if that leaves out calculation when 'other' == 'current'
                    if(op != cp){

                        GravitationalForce(current, other, Fxnew, Fynew);

                    }//end if

                }//end for(other planets)

                //Calculate new acceleration from new forces at new position
                r = current.radiusFromSun();
                a_x_new = -(G/(pow(r,3))*current.pos[0]) + Fxnew/current.mass;
                a_y_new = -(G/(pow(r,3))*current.pos[1]) + Fynew/current.mass;

                //Calculate new velocity for 'current' based on Verlets velocity algorithm
                current.vel[0] += 0.5*(a_x + a_x_new)*dt;
                current.vel[1] += 0.5*(a_y + a_y_new)*dt;


                //Calculate the total kinetic energy, potential energy and momentum for this timestep
                kinetic += current.KineticEnergy();
                potential += current.PotentialEnergySun();
                angular += current.AngularMom();

                //write to file
                if(cp == 0){
                myfile << current.pos[0] <<" "<< current.pos[1]<< endl;

                }

                if(cp == 1){
                myfile3 << current.pos[0] <<" "<< current.pos[1]<< endl;

                }

                if(cp == 2){
                    myfile4 << current.pos[0] << " " << current.pos[1]<<endl;
                }

                if(cp == 3){
                    myfile5 << current.pos[0] << " " << current.pos[1]<<endl;
                }

                if(cp == 4){
                    myfile6 << current.pos[0] << " " << current.pos[1] <<endl;
                }

                if(cp == 5){
                    myfile7 << current.pos[0] << " " << current.pos[1] <<endl;
                }

                if(cp == 6){
                    myfile8 << current.pos[0] << " " << current.pos[1] <<endl;
                }

                if(cp == 7){
                    myfile9 << current.pos[0] << " " << current.pos[1] <<endl;
                }

            }//end for (current)


            //Write potential, kinetick energy og angular momentum to file
            myfile2 << kinetic << " " << potential << " " << angular << endl;

            time +=dt;


        }//end while

        //close the file
        myfile.close();
        myfile2.close();
        myfile3.close();
        myfile4.close();
        myfile5.close();
        myfile6.close();
        myfile7.close();
        myfile8.close();
        myfile9.close();

}

void functions::VerletVMercur(double total_time, int N)
{
        //Define time step
        double dt = total_time/((double) N);

        //initialize time
        double time = 0.0;

        //initialize kinetic, potential and angular momentum
        double angularm;

        //Lightspeed in AU/yr
        double c = 63239.7263;

        //r-vectors and counter
        double radis[3];
        double teller = 2;

        //Decleare the relative factor
        double relative;

        //Initializing files
        std::ofstream myfile;
        myfile.open ("PeriphelonMercury.txt");

        //Initializing acceleration and force-components
        double a_x, a_y,a_x_new,a_y_new, xmin, ymin, rmin, periangle;

        //starting while-loop that goes until total_time is reached
        while(time < total_time){

                 //Setting energies, ang.mom to zero for this timestep
                 angularm = 0;

                //Create pointer that points to the right element in 'planets'
                planet &current = planets[0];

                //calculate angular momentum and radius
                angularm = (current.AngularMom())/current.mass;

                //radius
                double r = current.radiusFromSun();

                //Update r[0] here
                double remi;
                remi = abs(remainder(teller,2));

                if(remi == 0){
                    radis[0] = current.radiusFromSun();
                }
                if(remi != 0){
                    radis[2] = current.radiusFromSun();
                }

                //calculate the relative factor
                relative = 1 + (3*pow(angularm,2))/(pow(r,2)*pow(c,2));

                //Calculate the force WITH RELATIVE FACTOR
                double F = -((current.mass*G)/(pow(r,2)))*relative;

                //Calculate acceleration at current position from forces
                a_x = F*(current.pos[0]/r)/current.mass;
                a_y = F*(current.pos[1]/r)/current.mass;


                //calculate new position for 'current' from acceleration, based on Verlet Velocity algorithm
                current.pos[0] += current.vel[0]*dt + 0.5*dt*dt*a_x;
                current.pos[1] += current.vel[1]*dt + 0.5*dt*dt*a_y;

                radis[1] = current.radiusFromSun();

                //Check here!
                //if yes, saves the new minimum position
                if(radis[1] > radis[0] && radis[0] < radis[2]){
                    rmin = current.radiusFromSun();
                    xmin = current.pos[0];
                    ymin = current.pos[1];
                    myfile << atan(ymin/xmin) << endl;
                }//end if


                //calculate angular momentum and radis[1] and r
                angularm = (current.AngularMom())/current.mass;
                r = current.radiusFromSun();


                //calculate the relative factor
                relative = 1 + (3*pow(angularm,2))/(pow(r,2)*pow(c,2));

                //Calculate the force WITH RELATIVE FACTOR
                F = -((current.mass*G)/(pow(r,2)))*relative;

                //Calculate acceleration at current position from forces
                a_x_new = F*(current.pos[0]/r)/current.mass;
                a_y_new = F*(current.pos[1]/r)/current.mass;


                //Calculate new velocity for 'current' based on Verlets velocity algorithm
                current.vel[0] += 0.5*(a_x + a_x_new)*dt;
                current.vel[1] += 0.5*(a_y + a_y_new)*dt;

                time +=dt;
                teller++;


        }//end while


        //Calculates the periphelion angle of the last periphelion! :)
        periangle = atan(ymin/xmin); //NOT SAFE
        cout << "Periangle: " << periangle << "........." << endl;
        cout << "xmin: " << xmin << "........" << endl;
        cout << "ymin: " << ymin << "........" << endl;
        cout << "rmin: " << rmin << "......." << endl;

        myfile.close();

}


