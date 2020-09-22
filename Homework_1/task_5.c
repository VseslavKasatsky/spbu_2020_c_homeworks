#include <stdio.h>
#include <stdlib.h>
int const SIZE = 9;
int helper(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int arr[9] = { 4, 7, 1, 4, 9, 2, 3, 9, 7 };
	int i = 0, answer = 0;
	qsort(arr, SIZE, sizeof(int), helper);
	for (i = SIZE - 1; i > 0; i--)
	{
		if (arr[i] == arr[i - 1])
		{
			answer = arr[i];
			break;
		}
	}
	printf("%d", answer);
	return 0;
}