#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i = 0, number_arr[4] = { 0 }, j = 0, check_arr[4] = { 0 }, check = 0, flag = 1;
	for (i = 0; i < 4; i++)
	{
		srand(time(NULL));
		while (i < 4)
		{
			number_arr[i] = rand() % 10;
			for (j = 0; j < i; j++)
			{
				if (number_arr[i] == number_arr[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				//printf("%d", number_arr[i]); - answer
				i++;
			}
			flag = 1;
		}
	}
	while (1)
	{
		int cow = 0, bull = 0;
		scanf("%d", &check);
		for (i = 3; i >= 0; i--)
		{
			check_arr[i] = check % 10;
			check = check / 10;
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (check_arr[i] == number_arr[j])
				{
					if (i == j)
					{
						bull++;
					}
					else
					{
						cow++;
					}
				}
			}
		}
		if (bull != 4)
		{
			printf("%db %dc", bull, cow);
		}
		else
		{
			printf("YOU WIN!");
			break;
		}

	}

	return 0;
}

