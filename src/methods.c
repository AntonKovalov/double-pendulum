#include "methods.h"

void euler(double theta_1, double theta_2, double omega_1, double omega_2, double alfa_1, double alfa_2) {
    
    double current_time = 0;
    FILE* file; 
    file = fopen("data.xlsx", "w+");
    do {
        current_time += TIME_STEP;
        
        theta_1 += omega_1*TIME_STEP;
        theta_2 += omega_2*TIME_STEP;
        
        omega_1 += alfa_1*TIME_STEP;
        omega_2 += alfa_2*TIME_STEP;

        compute_angular_acceleration(theta_1, theta_2, omega_1, omega_2, &alfa_1, &alfa_2);
        write_data(file, theta_1, theta_2);
    } while(current_time < TOTAL_TIME);
    fclose(file);
}

void rungee_kutta(double theta_1, double theta_2, double omega_1, double omega_2, double alfa_1, double alfa_2) {
}
