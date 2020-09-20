#include <stdio.h>
const int N = 11;
int main()
{
	int arr[11] = { 5, 0, 1, 5, 2, 0, 6, 0, 3, 7, 0 };
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j < N - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[N - 1] = 0;
		}
	}
	for (i = 0; i < N; ++i)
	{
		printf("%d ", arr[i]);
	}
}
//В первом файле на HWproj используется другая логика программы, где массив сортируется