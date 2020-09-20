#include <stdio.h>
#include <stdlib.h>
const int N = 11;
int sorter(const void* b, const void* a)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int arr[11] = { 5, 0, 1, 5, 2, 0, 6, 0, 3, 7, 0 };
	int i = 0;
	qsort(arr, N, sizeof(int), sorter);
	for (i = 0; i < N; ++i)
	{
		printf("%d ", arr[i]);
	}
}