#define EXTERN
#include "init.h"


void init(double* theta_1, double* theta_2, double* omega_1, double* omega_2, double* alfa_1, double* alfa_2) {
    
    /**
    theta - angle                 [rad]
    omega - angular velocity      [rad/s]
    alfa  - angular acceleration  [rad/s^2]
    **/

    scanf("%lf %lf %lf %lf", theta_1, theta_2, omega_1, omega_2);
    printf("initital angles: %lf %lf [rad]\ninitial velocities: %lf %lf [rad/s]\n", *theta_1, *theta_2, *omega_1,* omega_2);
    compute_angular_acceleration(*theta_1, *theta_2, *omega_1, *omega_2, alfa_1, alfa_2);

}
