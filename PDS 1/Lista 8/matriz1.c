#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gereaNum(int k){
    return (rand() % k) + 1;
}

void zerar(int i, int jnt n, int m, int matriz[n][m])

void preencher(int n, int m, int k, int matriz[n][m]) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        
            matriz[i][j] = gereaNum(k);

        }
    }
    

}

void printar_vetor(int n, int m, int matriz[n][m]) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        
            printf("%d ", matriz[i][j]);

        }

        printf("\n");
    }

}

procurar_sequencia(int n, int m, int k, int matriz[n][m]) {

    for (int i = 0; i < n; i++)
    {
        int cont = 0;
        for (int j = 1; j < m-1; j++)
        {
        
            if(matriz[i][j] == matriz[i][j-1])
                cont++;
            else if(matriz[i][j] != matriz[i][j-1])
            {
                if(cont >= 2)
                    zerar(cont);
                cont = 0;
            }
            
                

        }
        if(cont >= 2)


        printf("\n");
    }
    
}

int main() {

    srand(time(NULL)); 
    int n,m,k;

    // pritnf("Digite o valor de M (Linhas) \n");
    // scanf("%d", &m);

    // pritnf("Digite o valor de N (Colunas) \n");
    // scanf("%d", &n);

    // pritnf("Digite o número máximo K \n");
    // scanf("%d", &k);

    n = 5;
    m = 4;
    k = 3;

    int matriz[n][m];

    preencher(n , m, k, matriz);
    printar_vetor(n , m, k, matriz);

    


    return 0;
}