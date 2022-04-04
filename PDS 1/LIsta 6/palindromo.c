#include <stdio.h>
#include <string.h>

int palindromo(char str[], int start, int final){

    if (start >= strlen(str)/2)
        return 1;
    if (str[start] != str[final-1])
    {
        //printf("%d, %d \n", start, final);
        return 0;
    }
        

    return palindromo(str, start+1, final-1);
    
}

int main(){

    char linha[128];
    printf("digite uma palavra:\n");
    fgets(linha, 128, stdin);

    if(palindromo(linha,  0, strlen(linha) - 1) == 1){
        printf("Eh um palindormo\n");
    } else {
        printf("Nao Eh um palindormo\n");
    }


    return 0;
}