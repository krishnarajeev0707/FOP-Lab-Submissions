// Write a C program to generate pseudo random numbers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main() {
    int n, i;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    srand(time(0));
    printf("Generated random numbers:\n");
    for (i = 0; i < n; i++) {
        int random_number = rand();
        printf("%d \n", random_number);
    }
    printf("\n");
}