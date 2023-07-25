#include <stdlib.h>
#include <stdio.h>

int Fib(int n) {
    if (n <= 2)
        return 1;
    else
    return Fib(n-1) + Fib(n-2);
}

int main(int argc, char *argv[]) {
    int f;
    f = Fib(atoi(argv[1]));
    printf("%d\n\n",f);
}
