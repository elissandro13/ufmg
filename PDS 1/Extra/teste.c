#include <stdio.h>

void troca(float *a, float *b) {
    
    float c;
    
    c = *a;
    *a = *b;
    *b = c;
    
}

int main(){
    float a = 1;
    float b = 2;
    troca(&a,&b);
    printf("%f %f", a, b);
}