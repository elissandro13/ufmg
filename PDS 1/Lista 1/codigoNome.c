#include <stdio.h>

int main() {
    char *nome = "Elissandro";
    int y = 0;
    char *c;

    for(c = nome; *c != '\0'; c++){

        printf("%d ", *c);
    }

    return 0;
}
