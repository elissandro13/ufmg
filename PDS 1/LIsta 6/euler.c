#include <math.h>
#include <stdio.h>

int fatorial(int n) {

    int fat = 1;

    for (int i = 1; i <= n; i++)
    {
        fat *= i;
    }
    
    return fat;
}



int main() {

    double euler = 1;
    int n = 1;

    while(((double)1/fatorial(n)) >= pow(10,-6))
    {
        euler += (1.0/fatorial(n));
        n++;
        //printf("Euler  %lf\n",euler);
    }
    printf("Euler Final %lf",euler);
    return 0;
}

