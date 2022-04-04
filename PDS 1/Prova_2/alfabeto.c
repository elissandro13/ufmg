#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int classificaFrase(char *frase) {
    int alfabeto[26] = {};
    int numLetras = 0;

    /** do {

        printf("%c", frase[i]);
        i++;

    } while(frase[i] != '\0'); **/
        
        
    
    for(int i = 0; *(frase+i) != '\0'; i++) {

        if(*(frase+i) >= 'a' && *(frase+i) <= 'z'){
            printf("Valor %c %d\n", *(frase+i), (*(frase+i) - 'a') % 26);
            alfabeto[ ( (*(frase+i) - 'a') % 26) ]++;
        }
    }
    
    for(int i = 0; i > 26; i++) {
        
        if(alfabeto[i] != 0) numLetras++;
    }
    
    printf("Num: %d\n", numLetras);
    if(numLetras == 26) return 1;
    else if(numLetras >= 13) return 0;
    
    return -1;
}

int main(){

    printf("%d\n", classificaFrase("a,bc"));
    printf("%d\n", classificaFrase("abcd"));
    printf("%d\n", classificaFrase("aabb"));
    return 1;
}