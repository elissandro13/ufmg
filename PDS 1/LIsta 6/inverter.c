#include <stdio.h>
#include <string.h>



int main() {

    char c;
    char texto[200];
    int cont = 0;

    do {
        c = getc(stdin);
        if(c == '.')
            break;
        
        texto[cont++] = c;

    } while (1);


    //printf("Texto Invertido: %s", texto);

    for (int i = cont-1; i >= 0; i--)
    {
        printf("%c",texto[i]);
    }

    printf(".\n");
    

    return 0;
}