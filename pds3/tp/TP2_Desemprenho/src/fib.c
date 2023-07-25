#include <stdlib.h>
#include <stdio.h>

int Fib(int n) {
    int primeiro, segundo, atual;
    primeiro = segundo = 1;
    if (n < 3)
        return 1;
    else
    for (int i = 3; i <= n; i++){
        atual = segundo + primeiro;
        primeiro = segundo;
        segundo = atual;
    }
    
    return atual;
}

int main(int argc, char *argv[]) {
    int f;
    f = Fib(atoi(argv[1]));
    printf("%d\n\n",f);
}
