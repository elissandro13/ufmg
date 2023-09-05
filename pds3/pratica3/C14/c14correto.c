#include <stdio.h>

int main(void) {
  int n, i, fact;
  fact = 0;
  printf("Positive integer:");
  scanf("%d", &n);
  printf("Debug fact = %d", fact);
  for(i = 1; i<=n; i++) 
    fact = fact*i;

  printf("Factorial %d = %d\n", n, fact);
}