#include <stdio.h>
int factorial(int number)
{
	if (number > 0)
	{
		int result = 1;
		for (int i = 1; i <= number; i++)
		{
			result = result * i;
		}
		return result;
	}
	else if (number == 0)
	{
		return 1;
	}
	else if (number < 0)
	{
		return 0;
	}
}
int main()
{
	int number = 0;
	scanf("%d", &number);
	printf("%d", factorial(number));
	return 0;
}