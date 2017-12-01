#ifndef PROJECT5HEADER_H
#define PROJECT5HEADER_H

//Read input from terminal, and set up inital psi and vorticity
void read_input(double& dx, double& delta_time, double& finaltime, double &initialtime, int &dimension, int &option, char *argv[]);

//Initializes psi and vorticity array
void initialize(double*& psi, double*& vorticity, int stepnum, int option, double dx);

//Writes results to file
void output(double*& psi, double*& vorticity, int stepnum);

//Calculates next timestep with forward scheme, for solid boundaries
void forward_diff_solidb(double*& psi, double*& vorticity, int stepnum, double ola);

//Calculates next timestep with centered scheme, for solid boundaries
void center_diff_solidb(double *&psi, double *&vorticity, double *&first_vorticity, int stepnum, double ingvild, double ola, double time);

//Calculates next timestep with forward scheme, for periodic boundaries
void forward_diff_periodicb(double* psi, double* vorticity, int stepnum, double ola);

//Calculates next timestep with centered scheme, for periodic boundaries
void center_diff_periodicb(double*& psi, double*& vorticity, double*& first_vorticity, int stepnum, double ingvild, double ola, double time);

//Reuses code from project 1 to find psi next step
void tridiagonal_solidb(double*& psi, double*& force, double*& e1, double*& e2, double*& d, double dx, int stepnum);

//Reuses code from project 1 to find psi next step
void tridiagonal_periodicb(double*& psi, double*& force, double*& e1, double*& e2, double*& d, double dx, int stepnum);

//Armadillo to solve psi next time step for periodic boundary conditions.
void Armadillo_1D_periodic_solver(double*& psi, double*& force, int stepnum);

//------------------------------- 2D functions ------------------------------------------------------------------------------------------//

//Assigns initialvalues to the 2D matrix
void initialize2D(double **&psi2D, double **&vorticity2D, int stepnum, double dx, int option);

//writes to file for the 2D case
void output2d(double**& psi2D, double**& vorticity2D, int stepnum);

//Calculates next step in two dimensions forward difference
void forward_diff_solidb_2D(double** psi2D, double** vorticity2D, int stepnum, double ola);

//Calculates next step in two dimnesions with centered difference
void centered_diff_solidb_2D(double**& psi2D, double**& vorticity2D, double**& first_vorticity2D, int stepnum, double ingvild, double ola, double time);

//Solving psi for next time step with iterative method. Solid boundaries.
void Jacobi_Iterative_solidb_2D(double**& psi2D, double **&psi2D_temp, double**& vorticity2D, int stepnum, double jostein, double hanne, double jostein2);

//Solving psi for next time step with iterative method. Periodic boundaries.
void Jacobi_Iterative_periodicb_2D(double**& psi2D, double**& psi2D_temp, double**& vorticity2D, int stepnum, double jostein, double hanne, double jostein2);

//Calculates next step in two dimensions forward difference
void forward_diff_periodicb_2D(double**& psi2D, double**& vorticity2D, double**& first_vorticity2D, int stepnum, double ola);


#endif // PROJECT5HEADER_H
