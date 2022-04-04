#include <stdio.h>

int main(){

    double conta = 789.54;
    double rendimento  = 1.0056;

    conta *= rendimento;
    conta += 303.20;
    conta *= rendimento;
    conta -= 58.25;
    conta *= rendimento;


    printf("Conta: %.2lf", conta);

    return 0;
}