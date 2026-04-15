// Write a C program to input a binary number from the user and convert it into a decimal number.

#include <stdio.h>
#include <math.h>

void main() {
    long long binary;
    int decimal = 0, i = 0, rem;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary != 0) {
        rem = binary % 10;
        decimal += rem * pow(2, i);
        binary /= 10;
        i++;
    }

    printf("Decimal equivalent: %d\n", decimal);
}