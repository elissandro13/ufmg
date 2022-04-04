#include <stdio.h>

int main(){

    
    int n;

    long long int prdutoEscalar = 0;

    printf("Digite N\n");
    scanf("%d", &n);

    double u[n];
    double v[n];

    printf("Digite os %d do conjunto u\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &u[i]);
    }

    printf("Digite os %d do conjunto v\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        prdutoEscalar += u[i] * v[i];
    }

    printf("O produto escalar desses dois conjuntos eeh %lli", prdutoEscalar);
    
}