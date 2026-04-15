//Write a C function to compute the factorial of a number with and without recursion.

#include <stdio.h>

unsigned long long fact_recursive(int n);
unsigned long long fact_iterative(int n);

void main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial of %d (recursive): %llu\n", n, fact_recursive(n));
    printf("Factorial of %d (iterative): %llu\n", n, fact_iterative(n));
}
unsigned long long fact_recursive(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fact_recursive(n - 1);
}
unsigned long long fact_iterative(int n) {
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}