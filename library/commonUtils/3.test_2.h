#ifndef SPBU_2020_C_HOMEWORKS_3_TEST_2_H
#define SPBU_2020_C_HOMEWORKS_3_TEST_2_H

typedef struct Matrix Matrix;

Matrix* createMatrix();

void fillMatrix(Matrix* matrix);
void printMatrix(Matrix* matrix);
void printSaddlePoint(Matrix* matrix);

void destroyMatrix(Matrix* matrix);

#endif //SPBU_2020_C_HOMEWORKS_3_TEST_2_H
