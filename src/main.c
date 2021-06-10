#include "init.h"
#include "methods.h"
#include "utils.h"
#define EULER
//#define RUNGE_KUTTA

void simulate_double_pendulum(double*, double*, double*, double*, double*, double*);

int main() {
    double theta_1, theta_2, omega_1, omega_2, alfa_1, alfa_2;
    printf("Hello! This is an attempt to simulate double pendulum physics\n");
    printf("As this is the initial value problem - please input the following data: theta_1, theta_2, omega_1, omega_2\n");
    
    init(&theta_1, &theta_2, &omega_1, &omega_2, &alfa_1, &alfa_2);

    init_value_register[0] = theta_1; // initial positions
    init_value_register[1] = theta_2; //
    init_value_register[2] = omega_1; // initial velocities  
    init_value_register[3] = omega_2; //
    init_value_register[4] =  alfa_1; // initial accelerations  
    init_value_register[5] =  alfa_2; // 
    init_value_register[6] = l_ratio; // initial length ratio
    init_value_register[7] = m_ratio; // initial mass ratio
    
    simulate_double_pendulum(&theta_1, &theta_2, &omega_1, &omega_2, &alfa_1, &alfa_2);
}

void simulate_double_pendulum(double* theta_1, double* theta_2, double* omega_1, double* omega_2, double* alfa_1, double* alfa_2) {

    FILE* file;
    file = fopen("data-euler.xlsx", "w+");

    #ifdef EULER
    printf("Computing with Euler's method\n");
    
    printf("Varying length:\n");
    int change_factor = -1; 
    int is_finished = 0;   
    char i;
    printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", *theta_1, *theta_2, *omega_1, *omega_2, *alfa_1, *alfa_2);
    
    do {
       printf("\t%lf %lf\n", l_ratio, m_ratio);
       euler(file, *theta_1, *theta_2, *omega_1, *omega_2, *alfa_1, *alfa_2);
       l_ratio += change_factor*LENGTH_RATIO_STEP;
       
       if( equal(l_ratio, MIN_LENGTH_RATIO - 0.1, EQUALS_PRECISION_ERROR) ) {
            change_factor *= -1;
            l_ratio = init_value_register[6];
        }
       
       if( equal(l_ratio, MAX_LENGTH_RATIO + 0.1, EQUALS_PRECISION_ERROR) ) {
            is_finished = 1;
        }
       
    } while(!is_finished);
    
    printf("\nVarying mass:\n");
    l_ratio = init_value_register[6]; // reinitialization of variables
    change_factor = -1;               //
    is_finished = 0;                  //
    
    do {
       printf("\t%lf %lf\n", l_ratio, m_ratio);      
       euler(file, *theta_1, *theta_2, *omega_1, *omega_2, *alfa_1, *alfa_2);
       m_ratio += change_factor*MASS_RATIO_STEP;
       if( equal(m_ratio, MIN_MASS_RATIO - 0.1, EQUALS_PRECISION_ERROR) ) {
            change_factor *= -1;
            m_ratio = init_value_register[7];
        }
       
       if( equal(m_ratio, MAX_MASS_RATIO + 0.1, EQUALS_PRECISION_ERROR) ) {
            is_finished = 1;
        }
       
    } while(!is_finished);

    #endif

    #ifdef RUNGE_KUTTA
    // coming soon
    printf("Computing with Runge-Kutta method\n");
    #endif
    printf("End of simulation. Computed results were outputed to data.xlsx. Happy hacking and bye-bye!\n");
}


