#include "3.test_2.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Matrix {
    int** matrix;
    int length;
    int width;
};

Matrix* createMatrix()
{
    printf("Enter matrix parameters(length, width): ");
    int length = 0;
    int width = 0;
    scanf("%d%d", &length, &width);

    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->width = width;
    matrix->length = length;

    matrix->matrix = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; ++i) {
        matrix->matrix[i] = (int*)malloc(width * sizeof(int));
    }

    return matrix;
}

void fillMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->length; ++i) {
        printf("Enter %d numbers to [%d] matrix row: ", matrix->width, i);
        for (int j = 0; j < matrix->width; ++j) {
            scanf("%d", &matrix->matrix[i][j]);
        }
    }
}

void printMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->length; ++i) {
        for (int j = 0; j < matrix->width; ++j) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void printSaddlePoint(Matrix* matrix)
{
    int* indicesOfMinimumInLine = (int*)malloc(matrix->length * sizeof(int));
    memset(indicesOfMinimumInLine, 0, matrix->length * sizeof(int));
    int* indicesMaximumInColumn = (int*)malloc(matrix->width * sizeof(int));
    memset(indicesMaximumInColumn, 0, matrix->length * sizeof(int));

    int minimum = INT_MAX;
    for (int i = 0; i < matrix->length; ++i) {
        for (int j = 0; j < matrix->width; ++j) {
            if (matrix->matrix[i][j] < minimum) {
                minimum = matrix->matrix[i][j];
                indicesOfMinimumInLine[i] = j;
            }
        }
    }

    int maximum = INT_MIN;
    for (int i = 0; i < matrix->width; ++i) {
        for (int j = 0; j < matrix->length; ++j) {
            if (matrix->matrix[j][i] > maximum) {
                maximum = matrix->matrix[j][i];
                indicesMaximumInColumn[i] = j;
            }
        }
    }

    for (int i = 0; i < matrix->length; ++i) {
        for (int j = 0; j < matrix->width; ++j) {
            if ((indicesOfMinimumInLine[i] == j) && (indicesMaximumInColumn[j] == i)) {
                printf("%d[%d][%d]\n", matrix->matrix[i][j], i, j);
            }
        }
    }

    free(indicesMaximumInColumn);
    free(indicesOfMinimumInLine);
}

void destroyMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->length; ++i) {
        free(matrix->matrix[i]);
    }
    free(matrix);
}
