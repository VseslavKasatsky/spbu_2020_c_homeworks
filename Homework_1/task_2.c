#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void
doABarrelRoll(int *arrayOfValues, int begin, int end)
{
	int step = (end - begin + 1) / 2;
	for (int i = 0; i < step; ++i) {
		arrayOfValues[begin + i] += arrayOfValues[end - i];
		arrayOfValues[end - i] = arrayOfValues[begin + i] - arrayOfValues[end - i];
		arrayOfValues[begin + i] -= arrayOfValues[end - i];
	}
}

int
main()
{
	int M = 0, N = 0, *array = NULL;
	printf("Vvedite Dlini otrezkov M,N");
	scanf("%d %d", &M, &N);
	array = (int *)malloc((N + M) * sizeof(int));
	int i = 0, vault = 0;
	for (i = 0; i < N + M; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	doABarrelRoll(array, 0, M - 1);
	doABarrelRoll(array, M, (M + N - 1));
	doABarrelRoll(array, 0, (M + N - 1));
	for (i = 0; i < N + M; i++) {
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}