#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
void print_decomposed_number(int size, int* values)
{
    printf("%d", values[0]);
    for (int i = 1; i < size; ++i)
        printf("+%d", values[i]);
    printf("\n");
}

void decompose_number(int left_sum, int last_term, int size, int* values)
{
    if (left_sum == 0) {
        print_decomposed_number(size, values);
    }
    for (int i = last_term; i <= left_sum; ++i) {
        size++;
        values = (int*)realloc(values, sizeof(int) * (size));
        values[size - 1] = i;
        decompose_number(left_sum - i, i, size, values);
        size--;
    }
}
int main()
{
    int number = 0, size = 0, *values = NULL;
    printf("Enter the number to decompose : ");
    scanf("%d", &number);
    decompose_number(number, 1, size, values);
    free(values);
    return 0;
}