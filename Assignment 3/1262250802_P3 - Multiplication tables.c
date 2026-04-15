// Write a program in C to generate multiplication tables

#include <stdio.h>

void  main() {
    int num, i;

    printf("Enter Number for multiplication table: ");
    scanf("%d", &num);

    printf("\nMultiplication Table of %d:\n", num);
    for (i=1; i<=10; i++) {
        printf("%d x %d = %d\n",num, i, num*i);
    }
    printf("\n");
}