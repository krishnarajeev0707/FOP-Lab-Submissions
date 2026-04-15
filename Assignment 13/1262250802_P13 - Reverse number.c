// Write a program in C to accept a number from the user and print the digits of the number in reverse order

#include <stdio.h>

void main() {
    int num, reverse = 0, digit;
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }
    printf("Reversed Number: %d\n", reverse);
}