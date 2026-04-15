// Write a program in C to accept marks of five courses of a student and compute the result. A student is considered PASS if he/she scores 40 marks or more in each course. If the student passes, calculate the aggregate percentage and assign the grade as follows:
// Aggregate ≥ 75% : Distinction
// Aggregate ≥ 60% and < 75% : First Division
// Aggregate ≥ 50% and < 60% : Second Division
// Aggregate ≥ 40% and < 50% : Third Division

#include <stdio.h>
void main() {
	int m1,m2,m3,m4,m5,grade;
	printf("Enter sub1 marks (integer value): ");
	scanf("%d",&m1);
	printf("Enter sub2 marks (integer value): ");
	scanf("%d",&m2);
	printf("Enter sub3 marks (integer value): ");
	scanf("%d",&m3);
	printf("Enter sub4 marks (integer value): ");
	scanf("%d",&m4);
	printf("Enter sub5 marks (integer value): ");
	scanf("%d",&m5);
	grade=(m1+m2+m3+m4+m5)/5;
	if  (m1>=40 && m2>=40 && m3>=40 && m4>=40 && m5>=40) {
		if (grade>=75) {
			printf("Distinction");
		}
		else if (grade>=60 && grade<75) {
			printf("First Division");
		}
		else if (grade>=50 && grade<60) {
			printf("Second Division");
		}
		else if (grade>=40 && grade<50) {
			printf("Third Division");
		}
    }
	else {
		printf("Fail");
    }
}
