#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fat (int n) {
    int f;
    f = 1;
    while(n > 0){
        for (int i = 0; i < 100000; i++)
        {
            sin(1);
        }
        
        f *= n;
        n--;
    }
    return f;
}

int main(int argc, char *argv[]) {
    int f;
    f = fat(atoi(argv[1]));
    printf("%d\n\n",f);
}