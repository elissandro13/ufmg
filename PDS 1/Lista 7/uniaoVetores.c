

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

int gereaNum(){
    return rand() % 366;
}


int main() {

    srand(time(NULL)); 

    int v1[MAX];
    int v2[MAX];
    

    int v3[366] = {0};
     int v4[MAX];

    for (int i = 0; i < MAX; i++)
    {
        v1[i] = gereaNum();
        v2[i] = gereaNum();

        v3[v1[i]]++;
        v3[v2[i]]++;
    }


    //bubble_sort(v1,MAX);
   // bubble_sort(v2, MAX);
    

    for (int i = 0; i < MAX; i++)
    {
        
        printf("%d,", v1[i]);
    }

    printf("\n\n");

    for (int i = 0; i < MAX; i++)
    {
        
        printf("%d,", v2[i]);
    }

    printf("\n\nUniao: ");

    int cont = 0;
    for (int i = 0; i < 366; i++)
    {
        if(v3[i] >= 1){
            v4[cont++] = i;
        }
        //printf("%d,", v3[i]);
    }

    for (int i = 0; i < cont; i++)
    {

        printf("%d,", v4[i]);
    }

    


    return 0;
}