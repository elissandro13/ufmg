#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 60

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
    
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        //printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++) {
            //printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int gereaNum(){
    return rand() % 366;
}


int main() {

    srand(time(NULL)); 

    int v1[60];
    int v2[60];

    int v3[366] = {0};

    for (int i = 0; i < MAX; i++)
    {
        v1[i] = gereaNum();
        v2[i] = gereaNum();
    }

    int c = 0;

    bubble_sort(v1,MAX);
    bubble_sort(v2, MAX);
    
    for (int i = 0; i < 366; i++)
    {
        if(binarySearch(v1, 0, MAX, i) != -1 && binarySearch(v2, 0, MAX, i) != -1)
            v3[c++] = i; 
    }

    for (int i = 0; i < MAX; i++)
    {
        
        printf("%d,", v1[i]);
    }

    printf("\n\n");

    for (int i = 0; i < MAX; i++)
    {
        
        printf("%d,", v2[i]);
    }

    printf("\n\n");

    int cont = 0;
    for (int i = 0; i < c; i++)
    {
        printf("%d,", v3[i]);
    }

    


    return 0;
}