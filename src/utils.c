#include <stdio.h>
#include <math.h>
#include "init.h"
#include "utils.h"

void write_data(FILE* file, double current_time, double theta_1, double theta_2) {
    double x_1, x_2, y_1, y_2; 
    int is_period = is_close_to_period(theta_1, theta_2);

    if(is_period){
        printf("Period = %lf\n", current_time);
    }

    compute_coordinates(theta_1, theta_2, &x_1, &x_2, &y_1, &y_2);
    fprintf(file, DATA_FORMAT, current_time, theta_1, x_1, y_1, theta_2, x_2, y_2, is_period);
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

    *alfa_1 = ( -G*(2*m_1 + m_2)*sin(theta_1) - m_2*G*sin(theta_1 - 2*theta_2) - 2*sin(theta_1 - theta_2)*(omega_2*omega_2*l_2 + omega_1*omega_1*l_1*cos(theta_1 - theta_2)) )
              /
             ( l_1*(2*m_1 + m_2 - m_2*cos(2*(theta_1 - theta_2))) );

    *alfa_2 = ( 2*sin(theta_1 - theta_2)*(omega_1*omega_1*l_1*(m_1 + m_2) + G*(m_1 + m_2)*cos(theta_1) + omega_2*omega_2*l_2*m_2*cos(theta_1- theta_2) )  )
              /
             ( l_2*(2*m_1 + m_2 - m_2*cos(2*(theta_1 - theta_2))) );
}

int is_close_to_period(double theta_1, double theta_2) {
    int is_period = 0;
    
    if ( equal(theta_1, init_value_register[0], PERIOD_POSITION_ERROR) ) {
        if ( equal(theta_2, init_value_register[1], PERIOD_POSITION_ERROR) ) {
            if (periodic_count % 2 == 0 && periodic_count != 0){
                is_period = 1;
            }
            periodic_count++;
        }
    }
    return is_period;
}


int equal(double a, double  b, double precision_error) {
    return fabs(a - b) < precision_error;
}
