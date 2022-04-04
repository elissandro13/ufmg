#include <math.h>
#include <stdio.h>



int checkFib(int n)
{
    if(n == 1 || n == 0)
        return 1;
    
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
        if(fib[i] == n)
            return 1;
        if(fib[i] > n)
            return 0;
        
    }
}

int fibn(int n)
{
    int cont = 1;
    
    if(checkFib(n) == 1)
        return 0;
        
    for(int i = 0; i <= n; i++)
    {
        if(checkFib(i) == 0)
        {
            printf("O numero %d na pos %d\n", i, cont);
            cont++;

        }
    }
    
    return cont;
}

int main()
{
    printf("Resposta = %d\n", fibn(14));


    return 0;
}