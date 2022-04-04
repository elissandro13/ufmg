#include <stdio.h>


int main(){

    int nota;

    printf("Digite a nota: \n");
    scanf("%d",&nota);

    switch (nota)
    {
    case 10:
        printf("Conceito A \n");
        break;
    
    case 9:
        printf("Conceito A \n");
        break;

    case 8:
        printf("Conceito B \n");
        break;

    case 7:
        printf("Conceito C \n");
        break;

    case 6:
        printf("Conceito D \n");
        break;
    
    case 5:
        printf("Conceito E \n");
        break;

    default:

        printf("Conceito F\n");
        break;
    }

    return 0;
}