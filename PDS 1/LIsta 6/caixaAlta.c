#include <stdio.h>

int length(char *str){

    int cont = 0;
    int i = 0;
    while (*(str+i) != '\0')
    {
        i++;
    }

    return i-1;
}

int check(int c) {
    
    if(c >= 65 && c <= 90)
    {
        return 0;
    }

    return 1;
}

void converte(char *c) {

    *c = *c - 32;
}

int main()
{

    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);

    for (int i = 0; i < length(linha); i++)
    {
        if(check(linha[i]) == 1)
            converte(&linha[i]);
    }

    printf("Convertido: %s", linha);
    

    return 0;
}