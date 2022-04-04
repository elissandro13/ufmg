#include <stdio.h>

void inverter (int v[], int n){

    for (int i = 0; i < n/2; i++)
    {
        int tmp = v[i];
        v[i] = v[n-i];
        v[n-i] = tmp;
    }

    return;
}


int main()  {

    int n;
   

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);

    int v[n+1];
    

    printf("Digite os numeros do vetor\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    inverter(v,n-1);

    printf("Invertido\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    
    return 0;

}