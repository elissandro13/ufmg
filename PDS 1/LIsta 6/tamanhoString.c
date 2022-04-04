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
int main()
{
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);

    printf("O tamanho da string e: %d", length(linha));

    return 0;
}