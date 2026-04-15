// Write a program in C to check whether the given 3-digit number is an Armstrong number or not. 

#include <stdio.h>

void main() {
    int num, originalNum, remainder, result = 0;
    printf("Enter a 3-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder * remainder * remainder;
        originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
}