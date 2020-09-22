#include <stdio.h>
int const SIZE = 7;
int main()
{
	int arr[7][7];
	int i = 0, j = 0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			arr[i][j] = j + 1;
		}
	}
	//Массив [1,SIZE]
	int coordinate_x = SIZE / 2, coordinate_y = SIZE / 2, round = 0;
	printf("%d", arr[coordinate_y][coordinate_x]);
	for (;;)
	{
		if (round < SIZE - 1)
		{
			round++;
		}
		for (i = 0; i < round; i++)
		{
			coordinate_y = coordinate_y + 1;
			printf("%d", arr[coordinate_y][coordinate_x]);
		}
		if (coordinate_x == 0 && coordinate_y == SIZE - 1)
		{
			break;
		}
		for (i = 0; i < round; i++)
		{
			coordinate_x = coordinate_x + 1;
			printf("%d", arr[coordinate_y][coordinate_x]);
		}
		round++;
		for (i = 0; i < round; i++)
		{
			coordinate_y = coordinate_y - 1;
			printf("%d", arr[coordinate_y][coordinate_x]);
		}
		for (i = 0; i < round; i++)
		{
			coordinate_x = coordinate_x - 1;
			printf("%d", arr[coordinate_y][coordinate_x]);
		}
	}
	return 0;
}
