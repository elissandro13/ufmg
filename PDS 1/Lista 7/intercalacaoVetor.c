#include <stdio.h>


int main() {
    
    int x[10];
    int y[10];
    int z[10];

    printf("Digite os numeros do vetor x\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&x[i]);
    }

    printf("Digite os numeros do vetor y\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&y[i]);
    }
    
    int contx = 0;
    int conty = 0;

    for (int i = 0; i < 20; i++)
    {
        if(i % 2 == 0)
            z[i] = y[conty++];
        else
            z[i] = x[contx++];
    }

    for (int i = 0; i < 20; i++)
    {
        printf("Pos [%d] = %d\n", i, z[i]);
    }

    
    

    
    return 0;

}