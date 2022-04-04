#include <stdio.h>
#include "estatisca.h"

int main()
{

    printf("\nCauchy(2) = %lf", cauchy(2));

    printf("\nGumbel(0, 0.5, 2) = %lf", gumbel(0, 0.5, 2));

    printf("\nLaplace(-6, -5, 4) = %lf\n", laplace(-6, -5, 4));

    return 0;
}