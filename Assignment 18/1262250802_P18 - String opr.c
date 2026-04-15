// Write a C program that accepts a string from the user and performs the following string operations: 
// i)	Calculate length of string 
// ii)	String reversal 
// iii)	Equality check of two strings 
// iv)	Check palindrome 
// v)	Check substring

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // i) Calculate length of string
    int length = strlen(str) - 1; // Subtract 1 to exclude newline character
    printf("Length of the string: %d\n", length);

    // ii) String reversal
    printf("Reversed string: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    // iii) Equality check of two strings
    char str2[100];
    printf("Enter another string: ");
    fgets(str2, sizeof(str2), stdin);
    if (strcmp(str, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    // iv) Check palindrome
    int isPalindrome = 1;
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // v) Check substring
    char substring[50];
    printf("Enter a substring to search for: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Remove newline character
    if (strstr(str, substring)) {
        printf("The substring '%s' is found in the string.\n", substring);
    } else {
        printf("The substring '%s' is not found in the string.\n", substring);
    }
    return 0;
}