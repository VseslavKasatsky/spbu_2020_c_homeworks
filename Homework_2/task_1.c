#include <stdio.h>
#include <stdlib.h>
void printDecomposedNumber(int size, int* values)
{
    printf("%d", values[0]);
    for (int i = 1; i < size; ++i)
        printf("+%d", values[i]);
    printf("\n");
}

void decomposeNumber(int leftSum, int lastTerm, int size, int* values)
{
    if (leftSum == 0) {
        printDecomposedNumber(size, values);
    }
    for (int i = lastTerm; i <= leftSum; ++i) {
        size++;
        values[size - 1] = i;
        decomposeNumber(leftSum - i, i, size, values);
        size--;
    }
}
int main()
{
    int number = 0, size = 0;
    printf("Enter the number to decompose : ");
    scanf("%d", &number);
    int* values = malloc(number * sizeof(int));
    decomposeNumber(number, 1, size, values);
    free(values);
    return 0;
}