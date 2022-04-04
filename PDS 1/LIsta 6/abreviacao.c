#include <stdio.h>


int maiuscula(int c) {
    
    if(c >= 65 && c <= 90)
    {
        return 1;
    }

    return 0;
}


int main()
{
    char c;
    char texto[200];
    int cont = 0;

    do {
        c = getc(stdin);
        if(c == '.')
            break;
        
        texto[cont++] = c;

    } while (1);

    texto[cont] = '\0';

    int i = 0; 

     while(texto[i] != '\0')
     {

        if(maiuscula(texto[i]) == 1){

            if(i == 0)
                printf("%c.", texto[0]);
            
            else if (texto[i-1] == ' ' && texto[i] != ' '){
                printf("%c.", texto[i]);
            }
        }
         
        i++;

     }
     printf("\n");



    return 0;
}