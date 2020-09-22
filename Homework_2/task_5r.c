#include <stdio.h>

int factorial(int number)
{
	if (number > 1)
	{
		return number * factorial(number - 1);
	}
	else if (number == 0 || number == 1)
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
}

