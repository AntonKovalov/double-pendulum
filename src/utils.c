#include <stdio.h>
#include <math.h>
#include "init.h"
#include "utils.h"

void write_data(FILE* file, double theta_1, double theta_2) {
    double x_1, x_2, y_1, y_2;
    compute_coordinates(theta_1, theta_2, &x_1, &x_2, &y_1, &y_2);
    fprintf(file, "%lf\t%lf\t\t%lf\t%lf\n", x_1, y_1, x_2, y_2);
}

void compute_coordinates(double theta_1, double theta_2, double* x_1, double* x_2, double* y_1, double* y_2 ) {
    *x_1 = l_1*sin(theta_1);
    *y_1 = -l_1*cos(theta_1);

    *x_2 = *x_1 + l_2*sin(theta_2);
    *y_2 = *y_1 - l_2*cos(theta_2);
}
