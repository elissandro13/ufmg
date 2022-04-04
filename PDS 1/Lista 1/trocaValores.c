#include <stdio.h>

int main() {

    float a = 3.14159, b = 2.71828;
    float swap;

    swap = a;
    a = b;
    b = swap;

    printf("\nPI = %f", b);
    printf("\nEULER = %f", a);

    return 0;
}
