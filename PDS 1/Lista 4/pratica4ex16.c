#include <stdio.h>
#include <math.h>
#include "pratica4.h" 


int main() 
{
    int num1, num2;

    do {
        printf("Digite numeros maiores que Zero\n");
        scanf("%d %d", &num1, &num2);

    } while (num1 <= 0  || num2 <= 0);
    

    printf ("O mdc de %d e %d eh: %d\n", num1, num2, mdc(num1, num2));
    printf ("O mmc de %d e %d eh: %d\n", num1, num2, mmc(num1, num2));

    return 0;
}