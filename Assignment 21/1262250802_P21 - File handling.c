// Write a C program to copy contents of one file to another and print the contents of the destination file using file handling.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourceName[100], destName[100];
    char ch;
    printf("Enter source filename: ");
    scanf("%s", sourceName);
    printf("Enter destination filename: ");
    scanf("%s", destName);
    FILE *source = fopen(sourceName, "r");
    if (source == NULL) {
        printf("Error: Could not open source file '%s'.\n", sourceName);
        return 1;
    }
    FILE *dest = fopen(destName, "w+");
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }
    fclose(source);
    printf("File copied successfully.\n");
    rewind(dest);
    printf("\nDestination file %s will contain:\n", destName);
    while ((ch = fgetc(dest)) != EOF) {
        putchar(ch);
    }

    fclose(dest);
    return 0;
}