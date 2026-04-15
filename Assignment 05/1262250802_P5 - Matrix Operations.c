//Write a program in C to perform basic matrix operations such as:
// 1. Addition of two matrices
// 2. Saddle point of a matrix
// 3. Inverse of a matrix
// 4. Magic Square Matrix

#include <stdio.h>
#include <stdlib.h>

void matrix_addition(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]);
void find_saddle_point(int size, int matrix[size][size]);
void matrix_inverse(int size, int matrix[size][size], float inverse[size][size]);
int is_magic_square(int size, int matrix[size][size]);

float determinant(int size, float matrix[size][size]) {
    if (size == 1) return matrix[0][0];
    if (size == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    float det = 0.0;
    float submatrix[size - 1][size - 1];

    for (int col = 0; col < size; col++) {
        for (int i = 1; i < size; i++) {
            int sub_col = 0;
            for (int j = 0; j < size; j++) {
                if (j == col) continue;
                submatrix[i - 1][sub_col++] = matrix[i][j];
            }
        }
        float sign = (col % 2 == 0) ? 1.0f : -1.0f;
        det += sign * matrix[0][col] * determinant(size - 1, submatrix);
    }
    return det;
}

void get_cofactor_matrix(int size, float matrix[size][size], float cofactor[size - 1][size - 1], int r, int c) {
    int ci = 0;
    for (int i = 0; i < size; i++) {
        if (i == r) continue;
        int cj = 0;
        for (int j = 0; j < size; j++) {
            if (j == c) continue;
            cofactor[ci][cj++] = matrix[i][j];
        }
        ci++;
    }
}

void matrix_inverse(int size, int matrix[size][size], float inverse[size][size]) {
    float fmatrix[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            fmatrix[i][j] = (float)matrix[i][j];
    float det = determinant(size, fmatrix);
    printf("Determinant of the matrix: %.2f\n", det);
    if (det == 0) {
        printf("Inverse does not exist (determinant is 0).\n");
        return;
    }
    if (size == 1) {
        inverse[0][0] = 1.0f / fmatrix[0][0];
        return;
    }
    float adjugate[size][size];
    float cofactor[size - 1][size - 1];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            get_cofactor_matrix(size, fmatrix, cofactor, i, j);
            float minor_det = determinant(size - 1, cofactor);
            float sign = ((i + j) % 2 == 0) ? 1.0f : -1.0f;
            adjugate[j][i] = sign * minor_det;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] = adjugate[i][j] / det;
        }
    }
    printf("Inverse of the matrix (Adjugate / Determinant):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%8.2f ", inverse[i][j]);
        }
        printf("\n");
    }
}

void matrix_addition(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

void find_saddle_point(int size, int matrix[size][size]) {
    int saddle_point_found = 0;
    for (int i = 0; i < size; i++) {
        int min_row = matrix[i][0];
        int col_index = 0;
        for (int j = 1; j < size; j++) {
            if (matrix[i][j] < min_row) {
                min_row = matrix[i][j];
                col_index = j;
            }
        }
        int max_col = min_row;
        for (int k = 0; k < size; k++) {
            if (matrix[k][col_index] > max_col)
                max_col = matrix[k][col_index];
        }
        if (min_row == max_col) {
            printf("Saddle point found at (%d, %d): %d\n", i, col_index, min_row);
            saddle_point_found = 1;
        }
    }
    if (!saddle_point_found)
        printf("No saddle point found.\n");
}

int is_magic_square(int size, int matrix[size][size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += matrix[0][i];

    for (int i = 0; i < size; i++) {
        int row_sum = 0;
        for (int j = 0; j < size; j++) row_sum += matrix[i][j];
        if (row_sum != sum) return 0;
    }
    for (int j = 0; j < size; j++) {
        int col_sum = 0;
        for (int i = 0; i < size; i++) col_sum += matrix[i][j];
        if (col_sum != sum) return 0;
    }
    int diag_sum = 0;
    for (int i = 0; i < size; i++) diag_sum += matrix[i][i];
    if (diag_sum != sum) return 0;

    int anti_diag_sum = 0;
    for (int i = 0; i < size; i++) anti_diag_sum += matrix[i][size - 1 - i];
    if (anti_diag_sum != sum) return 0;

    return 1;
}

void main() {
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);
    int matrix1[size][size], matrix2[size][size], result[size][size];
    float inverse[size][size];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix1[i][j]);
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix2[i][j]);

    matrix_addition(size, matrix1, matrix2, result);
    printf("\nResult of Matrix Addition:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    printf("\n");
    find_saddle_point(size, matrix1);
    printf("\n");
    matrix_inverse(size, matrix1, inverse);
    printf("\n");
    if (is_magic_square(size, matrix1))
        printf("The first matrix is a magic square.\n");
    else
        printf("The first matrix is not a magic square.\n");
}

