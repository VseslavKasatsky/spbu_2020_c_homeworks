#include <stdio.h>
int const N = 9, M = 5;
//M-начало, N - конец
int main()
{
	int arr[14];
	int i = 0, vault;
	for (i = 0; i < N + M; i++)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < N; i++)
	{
		vault = arr[N + M - 1];
		for (int j = N + M - 1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = vault;
	}

	for (i = 0; i < N + M; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}