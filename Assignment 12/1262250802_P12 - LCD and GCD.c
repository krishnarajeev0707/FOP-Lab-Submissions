//Write a program in C to accept two numbers from the user and compute:
//a)	The smallest common divisor of the two numbers (other than 1, if any)
//b)	The Greatest Common Divisor (GCD) of the two numbers

#include <stdio.h>

void main () {
    int num1, num2, i, smallest_divisor = 0, gcd = 1;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    for (i = 2; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            smallest_divisor = i;
            break;
        }
    }
    int a = num1, b = num2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    if (smallest_divisor != 0) {
        printf("The smallest common divisor of %d and %d is: %d\n", num1, num2, smallest_divisor);
    } else {
        printf("There is no common divisor other than 1 for %d and %d.\n", num1, num2);
    }
    
    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd);
}