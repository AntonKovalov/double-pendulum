#ifndef INIT
#define INIT

#include <stdio.h>
#include <math.h>
#include "utils.h"

#define G 9.8f                    // kg/ms^2
#define LENGTH_RATIO_STEP 0.1f    // m/m
#define MASS_RATIO_STEP 0.1f      // kg/kg
#define TIME_STEP 0.01f           // s
#define TOTAL_TIME 60.0f          // s
#define m_1 1.f                   // kg
#define m_ratio 1.f               // kg/kg  m_1/m_2
#define l_1 1.f                   // m
#define l_ratio 1.f               // m/m  l_1/l_2
#define DATA_FORMAT "%lf\t\t%lf\t%lf\t%lf\t\t%lf\t%lf\t%lf\n"
#define DATA_HEAD_FORMAT "%c\t\t%c\t%c\t%c\t\t%c\t%c\t%c\n"
void init(double*, double*, double*, double*, double*, double*);
#endif
