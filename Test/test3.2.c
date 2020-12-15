#include "../library/commonUtils/3.test_2.h"
#include <stdio.h>

int main()
{
    Matrix* matrix = createMatrix();
    fillMatrix(matrix);
    printMatrix(matrix);
    printSaddlePoint(matrix);
    destroyMatrix(matrix);

    return 0;
}
