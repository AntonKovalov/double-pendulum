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
    m_1 = 1.0;                   // kg
    m_ratio = 1.0;               // kg/kg  m_1/m_2
    l_1 = 1.0;                   // m
    l_ratio = 1.0;               // m/m  l_1/l_2
}
