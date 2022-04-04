#include <stdio.h>

void imprimeLinha (int n)
{
    if (n == 1)
    {
        printf("1\n");
        return;
    }

    int numMaxLinha =   (n * (n + 1)) / 2;

    for (int i = numMaxLinha - n  + 1; i <= numMaxLinha; i++)
    {
        printf("%d ", i);
    }

    printf("\n");
}

int main(){


    int n;
    printf("Digite o numero de linhas: \n");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        imprimeLinha(i);
    }

    
    
}