// To accept the number of terms and find the sum of the sine series.

#include <stdio.h>
#include <math.h>

double factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

int main() {
    int n;
    double x, sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the value of x (in radians): ");
    scanf("%lf", &x);

    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sum += term;
    }
    printf("Sum of the sine series: %lf\n", sum);
    return 0;
}