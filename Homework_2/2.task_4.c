#include <stdio.h>
int main()
{
	int number = 0, arr[10] = { 0 }, j;
	scanf_s("%d", &number);
	while (number > 0)
	{
		arr[number % 10]++;
		number = number / 10;
	}
	number = 0;
	if (arr[0] != 0)
	{
		for (j = 1; j < 10; j++)
		{
			if (arr[j] != 0)
			{
				number = j;
				arr[j]--;
				break;
			}
		}
	}
	for (j = 0; j < 10; j++)
	{
		while (arr[j] != 0)
		{
			number = number * 10 + j;
			arr[j]--;
		}
	}
	printf("%d", number);
}
