#include <stdio.h>

int intToChar(int c){
    return c + '0';
}

int charToInt(char c){
    
    return c - '0';
}

int main() {

    char cpf[11];
    
    printf("Digite o cpf sem digito verificador: \n");

    for (int i = 0; i < 9; i++){
        scanf("%c", &cpf[i]);
    }

    //for (int i = 0; i < 9; i++){
    //    printf("%c", cpf[i]);
    //}

    int soma = 0;
    int num = 2;
    for (int i = 8; i >= 0; i--){
        soma += charToInt(cpf[i]) * num++;  
    }

    //printf("Soma = %d", soma);

    char d1 = 0;
    int d2 = 0;

    if (soma % 11 == 0 || soma % 11 == 1)
    {
        d1 = '0';
    }
    else
    {
        d1 = intToChar(11 - (soma % 11));
    }

    int soma2 = 0;

    cpf[9] = d1;

    //printf("\nD1= %c", cpf[9]);
   
    
    num = 2;

    for (int i = 9; i >= 0; i--){
        soma2 += charToInt(cpf[i]) * num++;
        //printf("\n %d  * %d", charToInt(cpf[i]), num-1);  
    }

    //printf("\nNUm = %d", num);
    if (soma2 % 11 == 0 || soma2 % 11 == 1)
    {
        d2 = 0;
    }
    else
    {
        d2 = 11 - (soma2 % 11);

    }

    printf("\nDigito verificador: %c%d", d1, d2);
    return 0;
}
