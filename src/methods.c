#include "methods.h"

void euler(FILE* file, double theta_1, double theta_2, double omega_1, double omega_2, double alfa_1, double alfa_2) {
    
    double current_time = 0;
    
    fprintf(file, "%c\t%c\n%lf\t%lf\n", 'l', 'm', l_ratio, m_ratio);
    fprintf(file, DATA_HEAD_FORMAT, 't', 'a', 'x', 'y', 'a', 'x', 'y' );
   
   do {
        current_time += TIME_STEP;
        
        theta_1 += omega_1*TIME_STEP;
        theta_2 += omega_2*TIME_STEP;
        
        omega_1 += alfa_1*TIME_STEP;
        omega_2 += alfa_2*TIME_STEP;
        
        compute_angular_acceleration(theta_1, theta_2, omega_1, omega_2, &alfa_1, &alfa_2);
        write_data(file, current_time, theta_1, theta_2);
    } while(current_time < TOTAL_TIME);
    
    fprintf(file, "\n\n");
    fclose(file);
    periodic_count = 0;   // reinitialize counter
}

void runge_kutta(double theta_1, double theta_2, double omega_1, double omega_2, double alfa_1, double alfa_2) {

    double current_time = 0;
    FILE* file; 
    file = fopen("data-runge-kutta.xlsx", "w+");
    fprintf(file, DATA_HEAD_FORMAT, 't', 'a', 'x', 'y', 'a', 'x', 'y' );
    do {
   
    } while(current_time < TOTAL_TIME);
    fclose(file);
}
