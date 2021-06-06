#include "init.h"


void compute_angular_acceleration(double theta_1, double theta_2, double omega_1, double omega_2, double* alfa_1, double* alfa_2) {
    *alfa_1 = ( -G*(2*m_1 + m_2)*sin(theta_1) -m_2*G*sin(theta_1 - 2*theta_2) - 2*sin(theta_1 - theta_2)*(pow(omega_2, 2)*l_2 + pow(omega_1, 2)*l_1*cos(theta_1 - theta_2)) ) 
              / 
             ( l_1*(2*m_1 + m_2 - m_2*cos(2*(theta_2 - theta_2)))  );


    *alfa_2 = ( 2*sin(theta_1 - theta_2)*(pow(omega_1, 2)*l_1*(m_1 + m_2) + G*(m_1 + m_2)*cos(theta_1) + pow(omega_2, 2)*l_2*m_2*cos(theta_1- theta_2) )  )
              /
             ( l_2*(2*m_1 + m_2 - m_2*cos(2*(theta_2 - theta_2)))  );
}

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
