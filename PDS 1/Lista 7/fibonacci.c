#include <stdio.h>


unsigned long long int fib(int n, unsigned long long int *vet) {

    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;

    if (*(vet+n) > 0)
            return *(vet+n);
    
    *(vet+n) = fib(n-1, vet) + fib(n-2, vet);

    return *(vet+n);
}


int main() {


    int n;
    unsigned long long int v[1001] = {0};

    while(1){

        printf("Digite o a posicao de fibonacci que deseja calcular/ -1 Para Sair\n")/
        scanf("%d",&n);

        if(n < 0 || n > 1000){
                break;
        }
        
        printf("Na posicao  %d o valor de Fibonacci eh %llu\n", n, fib(n, v));
    }


    
    return 0;

}