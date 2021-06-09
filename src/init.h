#ifndef INIT
#define INIT

#include <stdio.h>
#include <math.h>
#include "utils.h"

#define G 9.8f                       // kg/ms^2
#define LENGTH_RATIO_STEP 0.1f       // m/m
#define MASS_RATIO_STEP 0.1f         // kg/kg2
#define MAX_MASS_RATIO 2.0f          // kg/kg
#define MAX_LENGTH_RATIO 2.0f          // kg/kg
#define MIN_MASS_RATIO 0.2f          // kg/kg
#define MIN_LENGTH_RATIO 0.2f        // m/m
#define TIME_STEP 0.01f             // s
#define TOTAL_TIME 60.0f             // s
#define DATA_FORMAT "%lf\t\t%lf\t%lf\t%lf\t\t%lf\t%lf\t%lf\t%d\n"
#define DATA_HEAD_FORMAT "%c\t\t%c\t%c\t%c\t\t%c\t%c\t%c\n"
#define PERIOD_POSITION_ERROR 0.05    // rad
#define EQUALS_PRECISION_ERROR 0.001

#ifndef EXTERN
#define EXTERN extern
#endif

EXTERN double m_1;                   // kg
EXTERN double m_ratio;               // kg/kg  m_1/m_2
EXTERN double l_1;                   // m
EXTERN double l_ratio;               // m/m  l_1/l_2
EXTERN double init_value_register[8];
EXTERN int periodic_count;
void init(double*, double*, double*, double*, double*, double*);
#endif
