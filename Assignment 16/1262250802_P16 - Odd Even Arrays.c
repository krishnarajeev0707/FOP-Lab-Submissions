// To accept a list of N integers and partition the list into two sublists containing even and odd numbers.

#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of integers: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Even numbers:\n");
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Odd numbers:\n");
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}