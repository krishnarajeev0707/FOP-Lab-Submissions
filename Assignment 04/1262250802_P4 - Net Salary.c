// Write a C Program to calculate the salary of an employee given his basic pay (taken as input from the user). 
// Calculate gross salary of employee. 
// Let HRA be 10 % of basic pay and TA be 5% of basic pay. 
// Let employees pay professional tax as 2% of total salary. 
// Calculate net salary payable after deductions.

#include <stdio.h>
void main() {
    float b_pay, hra, ta, g_sal, p_tax, n_sal;

    printf("Enter the basic pay of the employee: ");
    scanf("%f", &b_pay);

    hra = 0.10 * b_pay; // HRA is 10% of basic pay
    ta = 0.05 * b_pay;  // TA is 5% of basic pay
    
    g_sal = b_pay + hra + ta; // Calculate gross salary
    p_tax = 0.02 * g_sal; // Professional tax is 2% of gross salary
    n_sal = g_sal - p_tax; // Calculate net salary after deductions

    printf("Gross Salary: %.2f\n", g_sal);
    printf("Professional Tax: %.2f\n", p_tax);
    printf("Net Salary Payable: %.2f\n", n_sal);
}