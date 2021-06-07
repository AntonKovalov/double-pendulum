#include <stdio.h>
#include <math.h>
#include "init.h"
#include "utils.h"

void write_data(FILE* file, double current_time, double theta_1, double theta_2) {
    double x_1, x_2, y_1, y_2;
    compute_coordinates(theta_1, theta_2, &x_1, &x_2, &y_1, &y_2);
    fprintf(file, DATA_FORMAT, current_time, theta_1, x_1, y_1, theta_2, x_2, y_2);
}

void compute_coordinates(double theta_1, double theta_2, double* x_1, double* x_2, double* y_1, double* y_2 ) {
    double m_2 = m_1/m_ratio;
    double l_2 = l_1/l_ratio;

    *x_1 = l_1*sin(theta_1);
    *y_1 = -l_1*cos(theta_1);

    *x_2 = *x_1 + l_2*sin(theta_2);
    *y_2 = *y_1 - l_2*cos(theta_2);
}

void compute_angular_acceleration(double theta_1, double theta_2, double omega_1, double omega_2, double* alfa_1, double* alfa_2) {
    double m_2 = m_1/m_ratio;
    double l_2 = l_1/l_ratio;
   
    *alfa_1 = ( -G*(2*m_1 + m_2)*sin(theta_1) -m_2*G*sin(theta_1 - 2*theta_2) - 2*sin(theta_1 - theta_2)*(pow(omega_2, 2)*l_2 + pow(omega_1, 2)*l_1*cos(theta_1 - theta_2)) )
              /
             ( l_1*(2*m_1 + m_2 - m_2*cos(2*(theta_2 - theta_2)))  );


    *alfa_2 = ( 2*sin(theta_1 - theta_2)*(pow(omega_1, 2)*l_1*(m_1 + m_2) + G*(m_1 + m_2)*cos(theta_1) + pow(omega_2, 2)*l_2*m_2*cos(theta_1- theta_2) )  )
              /
             ( l_2*(2*m_1 + m_2 - m_2*cos(2*(theta_2 - theta_2)))  );
}
