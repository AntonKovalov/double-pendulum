
#include "init.h"
#include "methods.h"

#define EULER
//#define RUNGEE_KUTTA

/** CONCEPT 

PDE used to solve the double pendulum systems are derived and finalized at the 
https://web.mit.edu/jorloff/www/chaosTalk/double-pendulum/double-pendulum-en.html

If the finite time T interval(TOTAL_TIME) is devided into n intervals, with the time step of h (TIME_STEP) then
n = T/h - intervals, and n+1 finite points k, where k belongs to [0, T], and i to [0, n+1]

Intial position and velocity pairs are given as an input [m, m/s] for both pendulum elements,
and then the following values are computed using equations for acceleration.


Eulers method
------

Runge-Kutta method
------
**/


void simulate_double_pendulum(double*, double*, double*, double*, double*, double*);

int main() {
    double theta_1, theta_2, omega_1, omega_2, alfa_1, alfa_2;
    printf("Hello! This is an attempt to simulate double pendulum physics\n");
    printf("As this is the initial value problem - please input the following data: theta_1, theta_2, omega_1, omega_2\n");
    init(&theta_1, &theta_2, &omega_1, &omega_2, &alfa_1, &alfa_2);
    simulate_double_pendulum(&theta_1, &theta_2, &omega_1, &omega_2, &alfa_1, &alfa_2);
}


void simulate_double_pendulum(double* theta_1, double* theta_2, double* omega_1, double* omega_2, double* alfa_1, double* alfa_2) {
    #ifdef EULER
    printf("Computing with Euler's method\n");
    euler(*theta_1, *theta_2, *omega_1, *omega_2, *alfa_1, *alfa_2);
    #endif

    #ifdef RUNEE_KUTTA
    // coming soon
    printf("Computing with Rungee-Kutta method\n");
    #endif
    printf("End of simulation. Computed results were outputed to data.xlsx. Happy hacking and bye-bye!\n");
}


