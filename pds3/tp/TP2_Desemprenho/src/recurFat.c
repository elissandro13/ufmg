#include <stdlib.h>
#include <stdio.h>

int fat (int n) {
    if (n<=0)
        return 1;
    else
    return n * fat(n-1);
}

int main(int argc, char *argv[]) {
    int f;
    f = fat(atoi(argv[1]));
    printf("%d\n\n",f);
}
