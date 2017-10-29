#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>

//Forward Euler implemented as a function to run in main.

using namespace std;

void forwardeuler(int NN, double T){

    //Calculating steplength h and time
    double N = NN;
    double totaltime = T;
    double h = totaltime/((double) N);
    double time = 0.0;

    //Initializing pi and D
    double pi = acos(-1);
    double D = 4*pi*pi;

    //Initializing the scaled positions, kin.energy, pot.energy and ang.mom.
    double x = 1.;
    double y = 0.;
    double vx = 0;
    double vy = 2*pi;
    double pot = 0;
    double kin = 0;
    double ang = 0;

    //Initializing files
    ofstream myfile;
    myfile.open ("EulerValues.txt");
    ofstream myfile2;
    myfile2.open("ConservedEulerValues.txt");

while(time < totaltime){

        //Calculate r and r3
        double r = sqrt(x*x + y*y);
        double rt = r*r*r;

        //calculating the i+1 position and i+2 velocity
        x += vx*h;
        y += vy*h;
        vx -= (h*D*x)/(rt);
        vy -= (h*D*y)/(rt);

        //Calculating the kinetick, potential and angular momentum
        double Mearth = 5.97*pow(10,24);
        double vtot = sqrt(vx*vx + vy*vy);
        double radis = sqrt(x*x + y*y);
        kin = 0.5*(vx*vx + vy*vy)*Mearth;
        pot = Mearth*D/radis;
        ang = Mearth*radis*vtot;

            //write to file
            myfile << x <<" " << y << endl;
            myfile2 << kin << " " << pot << " " << ang << endl;

        //set new timestep
        time += h;

        }//end while

    //close the file
    myfile.close();
    myfile2.close();

}//End Euler function
