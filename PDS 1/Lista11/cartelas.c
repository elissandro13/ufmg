#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ordenar(int arr[], int n){

     int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {

    int sorteados = 0;
    int lost = 0;
    int num[6] = {};
    char linha[100];
    FILE *arq;
    arq = fopen("cartelas.txt", "r");
    int n;


    /** while(feof(arq) == 0) {
        printf("Uno\n");
        fgets(linha, 100, arq);
        printf("%s", linha);
    } **/


    while(feof(arq) == 0) {
        //printf("assa");
        fgets(linha, 100, arq);

        char *token;
        int i = 0;

        num[0] = atoi(strtok(linha, " "));
        num[1] = atoi(strtok(NULL, " "));
        num[2] = atoi(strtok(NULL, " "));
        num[3] = atoi(strtok(NULL, " "));
        num[4] = atoi(strtok(NULL, " "));
        num[5] = atoi(strtok(NULL, " "));

        
        //printf("\nli: %d %d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4], num[5]);

        ordenar(num, 6);

        if(num[0] == 6 && num[1] == 9 && num[2] == 22 && num[3] == 23 && num[4] == 48 && num[5] == 52){
            sorteados++;
        }

        else if(num[0] == 4 && num[1] == 8 && num[2] == 15 && num[3] == 16 && num[4] == 23 && num[5] == 42) {
            lost++;
        }
    }


    fclose(arq);
    printf("Lost %d\n", lost);
    printf("Sorteado %d\n", sorteados);

    return 0;
}