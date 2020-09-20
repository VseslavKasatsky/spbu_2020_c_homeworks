#include <stdio.h>
#include <stdlib.h>
int randomizer()
{
	int number = 1;
	srand(1000);
	number = number + rand();
	return number % 10000;
}
int main()
{
	int number = randomizer(), arr[10]={0},check;
	printf("%d", number);
	while(1)
	{
		scanf_s("%d",&check);
	}
	return 0;
}

