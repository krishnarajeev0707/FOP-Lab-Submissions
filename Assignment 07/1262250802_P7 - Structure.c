//Write a C program to accept student details and display their result using an array of structures.

#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
void main() {
    int n;
    printf("Enter number of Students: ");
    scanf("%d",&n);
    struct Student students[n];
    int i;

    // Accept student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display student results
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s\n Roll Number: %d\n Marks: %.2f\n\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
}
