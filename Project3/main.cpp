#include <iostream>
#include "planet.h"
#include "functions.h"
#include <cmath>
#include "project3_header.h"

using namespace std;

int main()
{

//Declearing timestep
double N = 100*pow(10,6);
double T = 100;

// ---------------------------------Set up of Systems ------------------------------------------------------------------

//Initializes different systems for different tasks
functions TwoBodySystem;
functions ThreeBodySystem;
functions SolarSystem;
functions MercurPeri;

//Initializing planet earth for the TwoBodySystem (opg 3c, 3d)
planet earth(5.97*pow(10,24), 1,0,0, 2*M_PI);

//Initializing planets with values used by both ThreeBody and SolarSystem (opg 3e, 3f).
//Values from NASA, for 23.okt 2017 00:00Z
planet earth2(5.97*pow(10,24), 0.8679,0.49622,(-365)*8.7718*pow(10,-3),365*1.491359*pow(10,-2));
planet jupiter(1.9*pow(10,27),-4.56, -2.957, 365*4.0159*pow(10, -3), 365*(-5.9733)*pow(10,-3));
planet mars(6.4185*pow(10,23), -1.5869, 0.500156, -365*3.638385*pow(10,-3), -365*1.216093*pow(10, -2));
planet saturn(5.68319*pow(10,26), -3.2111*pow(10,-1), -1.0050*10, 365*(5.2704*pow(10,-3)), -365*1.9586*pow(10,-4));
planet uranus(86.8103*pow(10,24), 1.7849*pow(10,1), 8.8299, 365*(-1.7728*pow(10,-3)), 365*3.34197*pow(10, -3));
planet mercury(3.302*pow(10,23), -2.328*pow(10,-1), -3.9048*pow(10, -1), 365*1.8517*pow(10,-2), 365*(-1.2999*pow(10,-2)));
planet neptune(102.41*pow(10,24), 2.8619*pow(10,1), -8.8032, 365*9.0220*pow(10,-4), 365*3.0187*pow(10,-3));
planet venus(48.685*pow(10,23), -6.8594*pow(10,-1), 2.1032*pow(10,-1), 365*(-5.8677*pow(10,-3)), 365*(-1.9474*pow(10,-2)));

//Initializing Mercury for Mercuperi system, with values given (opg 3g)
planet mercuryP(3.302*pow(10,23),0.3075,0,0,12.44);

//Adding planets to the TwoBody system
TwoBodySystem.add(earth);

//Adding planets to the ThreeBody system
ThreeBodySystem.add(earth2);
ThreeBodySystem.add(jupiter);

//Adding planets to the full solar system
SolarSystem.add(earth2);
SolarSystem.add(jupiter);
SolarSystem.add(mars);
SolarSystem.add(saturn);
SolarSystem.add(uranus);
SolarSystem.add(mercury);
SolarSystem.add(neptune);
SolarSystem.add(venus);

//Adding mercury to the Mercur Periphelon system
MercurPeri.add(mercuryP);


// -------------------------------- Simulation of systems ---------------------------------------------------------------------

//Oppgave 3c)
//TwoBodySystem.Verlet(T,N);
//forwardeuler(N,T);

//Oppgave 3d)
// When running with different exponent for r, we temporarily rewrite Verlet function :)
//TwoBodySystem.Verlet(T,N);

//Oppgave 3e)
//ThreeBodySystem.Verlet(T,N);

//Oppgave 4e)
//SolarSystem.Verlet(T,N);

//Oppgave 3g)
//When running without relative correction we rewrite VerletMercur temporarily.
MercurPeri.VerletVMercur(T,N);

cout << remainder(2.0,2.0) << endl;
cout << endl << endl << "Your sun ran out of fuel, please restart your system." << endl << endl;

return 0;

}
