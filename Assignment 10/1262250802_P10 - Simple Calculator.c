// Write a program in C to simulate a simple calculator that performs basic arithmetic operations 
// such as addition, subtraction, multiplication, and division. The calculator should also perform 
// special operations like computing xʸ (power) and x! (factorial).

#include <stdio.h>
#include <math.h>

void main() {
    int choice;
    float num1, num2, result;
    int n, i;
    unsigned long long factorial = 1;

    printf("-----SIMPLE CALCULATOR MENU-----\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n-----ADDITION OPERATION-----\n");
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.0f\n", result);
            break;
        case 2:
        printf("\n-----SUBTRACTION OPERATION-----\n");
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.0f\n", result);
            break;
        case 3:
            printf("\n-----MULTIPLICATION OPERATION-----\n");
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.0f\n", result);
            break;
        case 4:
            printf("\n-----DIVISION OPERATION-----\n");
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("\n-----POWER CALCULATION-----\n");
            printf("Enter base and exponent numbers: ");
            scanf("%f %f", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %.0f\n", result);
            break;
        case 6:
            printf("\n-----FACTORIAL CALCULATION-----\n");
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);
            if (n < 0) {
                printf("Error: Factorial of a negative number is not defined.\n");
            } else {
                for (i = 1; i <= n; i++) {
                    factorial *= i;
                }
                printf("Factorial of %d = %llu\n", n, factorial);
            }
            break;
        default:
            printf("Invalid choice! Please select a valid operation.\n");
    }
}
