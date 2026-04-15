// Write a program in C to accept a number from the user and compute the following:
//  Square root of the number
//  Square of the number
//  Cube of the number
//  Check whether the number is prime
//  Factorial of the number
//  Prime factors of the number

#include <stdio.h>
#include <math.h>

void main() {
    int choice, n, i;
    float num, result;
    unsigned long long factorial = 1;
    int isPrime;
    printf("-----SIMPLE CALCULATION MENU-----\n");
    printf("1. Square Root\n");
    printf("2. Square\n");
    printf("3. Cube\n");
    printf("4. Check Prime\n");
    printf("5. Factorial\n");
    printf("6. Prime Factors\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    printf("Enter a number: ");
    scanf("%f", &num);
    n = (int)num;

    switch (choice) {
        case 1:
            printf("\n-----SQUARE ROOT-----\n");
            if (num >= 0) {
                result = sqrt(num);
                printf("Square Root of %.2f is %.2f\n", num, result);
            } else {
                printf("Error: Square root of negative number is not defined.\n");
            }
            break;
        case 2:
            printf("\n-----SQUARE-----\n");
            result = num * num;
            printf("Square of %.2f is %.2f\n", num, result);
            break;
        case 3:
            printf("\n-----CUBE-----\n");
            result = num * num * num;
            printf("Cube of %.2f is %.2f\n", num, result);
            break;
        case 4:
            printf("\n-----CHECK PRIME-----\n");
            if (n <= 1) {
                isPrime = 0;
            } else {
                isPrime = 1;
                for (i = 2; i <= sqrt(n); i++) {
                    if (n % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }
            }
            if (isPrime) {
                printf("%d is a prime number.\n", n);
            } else {
                printf("%d is not a prime number.\n", n);
            }
            break;
        case 5:
            printf("\n-----FACTORIAL-----\n");
            if (n < 0) {
                printf("Error: Negative number\n");
            } else {
                for (i = 1; i <= n; i++) {
                    factorial *= i;
                }
                printf("Factorial of %d is %llu\n", n, factorial);
            }
            break;
        case 6:
            printf("\n-----PRIME FACTORS-----\n");
            if (n <= 1) {
                printf("No prime factors for numbers less than or equal to 1.\n");
            } else {
                int original_n = n;
                int factor = 2;
                printf("Prime factors of %d are: ", original_n);
                while (factor * factor <= original_n) {
                    if (original_n % factor == 0) {
                        printf("%d ", factor);
                        while (original_n % factor == 0) {
                            original_n /= factor;
                        }
                    }
                    factor++;
                }
                if (original_n > 1) {
                    printf("%d", original_n);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice\n");
    }
}