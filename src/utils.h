#ifndef UTILS
#define UTILS
void write_data(FILE*, double, double, double);
void compute_coordinates(double, double, double*, double*, double*, double*);
void compute_angular_acceleration(double, double, double, double, double*, double*);
int is_close_to_period(double, double);
int equal(double, double, double);
#endif
