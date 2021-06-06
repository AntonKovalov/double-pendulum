#ifndef INIT
#define INIT

#include <stdio.h>
#include <math.h>

#define G 9.8f                    // kg/ms^2
#define LENGTH_RATIO_STEP 0.1f    // m/m
#define MASS_RATIO_STEP 0.1f      // kg/kg
#define TIME_STEP 0.01f           // s
#define TOTAL_TIME 20.0f          // s
#define m_1 1
#define m_2 1
#define l_1 1
#define l_2 1

void init(double*, double*, double*, double*, double*, double*);
void compute_angular_acceleration(double, double, double, double, double*, double*);
#endif
