#include <math.h>


double cauchy(double x){
    return 1 / (M_PI * (1 + (x*x)));
}

double gumbel(double x, double u ,double b){

    double z = (x - u) / b;

    return (1 / b) * exp(-1 * (z + exp(-1*z)));
}

double laplace(double x, double u, double b){
    return (1 / (2*b)) * exp((-1 * fabs(x - u)) / b);
}