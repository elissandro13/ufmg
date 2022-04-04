

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

int gereaNum(){
    return rand() % 1000;
}


int main() {

    srand(time(NULL)); 

    int v1[MAX];
    int vetor_contagem[1000] = {0};
    

    for (int i = 0; i < 50000; i++)
    {
        
        int k = gereaNum();
        vetor_contagem[k]++;
    }


    int maior = 0;
    int menor = 1000;
    int maiorPos = 0;
    int menorPos = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        
        if(vetor_contagem[i] > maior){
            maior = vetor_contagem[i];
            maiorPos = i;
        }

        if(vetor_contagem[i] < menor){
            menor = vetor_contagem[i];
            menorPos = i;
        }
    }

    printf("O numero que mais apareceu foi %d e o que menos apareceu foi %d, com respectivamente com %d e %d. A diferenca entre os dois eh %d", maiorPos, menorPos, maior, menor, maior - menor);

    
    


    return 0;
}