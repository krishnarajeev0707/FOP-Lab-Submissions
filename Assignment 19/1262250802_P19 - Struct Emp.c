// Create Structure EMPLOYEE for storing details (Name, Designation, gender, Date of Joining and Salary). Define function members to compute 
// a) total number of employees in an organization 
// b) count of male and female employee 
// c) Employee with salary more than 10,000 
// d) Employee with designation “Asst Manager”

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
struct EMPLOYEE {
    char name[50];
    char designation[50];
    char gender;
    int dateOfJoining;
    double salary;
};
struct EMPLOYEE employees[MAX_EMPLOYEES];
int employeeCount = 0;

void stripNewline(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEmployees() {
    printf("Enter number of employees to add: ");
    int n;
    scanf("%d", &n);
    flushBuffer();
    if (employeeCount + n > MAX_EMPLOYEES) {
        printf("Cannot add %d employees. Max capacity is %d.\n", n, MAX_EMPLOYEES);
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("\n--- Employee %d ---\n", employeeCount + 1);
        printf("Enter employee name: ");
        fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
        stripNewline(employees[employeeCount].name);
        printf("Enter employee designation: ");
        fgets(employees[employeeCount].designation, sizeof(employees[employeeCount].designation), stdin);
        stripNewline(employees[employeeCount].designation);
        printf("Enter employee gender (M/F): ");
        scanf(" %c", &employees[employeeCount].gender);
        printf("Enter date of joining (DDMMYYYY): ");
        scanf("%d", &employees[employeeCount].dateOfJoining);
        printf("Enter employee salary: ");
        scanf("%lf", &employees[employeeCount].salary);
        flushBuffer();
        employeeCount++;
    }
}
void countEmployees() {
    printf("Total number of employees: %d\n", employeeCount);
}
void countGender() {
    int maleCount = 0, femaleCount = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].gender == 'M' || employees[i].gender == 'm')
            maleCount++;
        else if (employees[i].gender == 'F' || employees[i].gender == 'f')
            femaleCount++;
    }
    printf("Male employees  : %d\n", maleCount);
    printf("Female employees: %d\n", femaleCount);
}
void employeesWithHighSalary() {
    printf("Employees with salary more than 10,000:\n");
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary > 10000) {
            printf("  %s (%.2f)\n", employees[i].name, employees[i].salary);
            found = 1;
        }
    }
    if (!found) printf("  None found.\n");
}
void employeesWithDesignation() {
    printf("Employees with designation 'Asst Manager':\n");
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].designation, "Asst Manager") == 0) {
            printf("  %s\n", employees[i].name);
            found = 1;
        }
    }
    if (!found) printf("  None found.\n");
}

int main() {
    printf("=== Add Employees ===\n");
    addEmployees();
    printf("\n=== a) Total Employees ===\n");
    countEmployees();
    printf("\n=== b) Gender Count ===\n");
    countGender();
    printf("\n=== c) High Salary (> 10,000) ===\n");
    employeesWithHighSalary();
    printf("\n=== d) Asst. Managers ===\n");
    employeesWithDesignation();
    return 0;
}