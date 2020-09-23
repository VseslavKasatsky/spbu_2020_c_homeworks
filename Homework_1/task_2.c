#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void doABarrelRoll(int* arrayOfValues, int begin, int end)
{
    int step = (end - begin + 1) / 2;
    for (int i = 0; i < step; ++i) {
        arrayOfValues[begin + i] += arrayOfValues[end - i];
        arrayOfValues[end - i] = arrayOfValues[begin + i] - arrayOfValues[end - i];
        arrayOfValues[begin + i] -= arrayOfValues[end - i];
    }
}

int main()
{
    int M = 0, N = 0, *array = NULL;
    printf("Enter the lengths of the line segments M and N: ");
    scanf("%d %d", &M, &N);
    array = (int*)malloc((N + M) * sizeof(int));
    for (int i = 0; i < N + M; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    doABarrelRoll(array, 0, M - 1);
    doABarrelRoll(array, M, (M + N - 1));
    doABarrelRoll(array, 0, (M + N - 1));
    for (int i = 0; i < N + M; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}