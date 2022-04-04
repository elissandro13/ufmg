#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int calculaOperacao(char *string1, char *string2) {
    int op = 0;

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    int menor, maior;
    menor = maior = 0;

    if(len1 > len2) {

        maior = len1;
        menor = len2;
        for (int i = menor; i < maior; i++)
        {
            op += string1[i] + 'z' + 1;
        }
        
    }   
    else {

        maior = len2;
        menor = len1;
       for (int i = menor; i < maior; i++)
        {
            op += string2[i] - 'a'  + 1;
        }
    }

    for (int i = 0; i < menor; i++)
    {
        
        if(string2[i] - string1[i] > 0) 
            op += string2[i] - string1[i];
        else if(string2[i] - string1[i] < 0){
            op += (string2[i] - string1[i]) + 27;
        }

        //printf("Op: %d\n", op);   
    }




    return op;
}

int main() {
    //printf("%d", (int)' ');
    printf("%d", calculaOperacao("ba", "bab"));
    return 1;
}