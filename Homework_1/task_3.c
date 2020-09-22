#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int const SIZE = 1000;

void main()
{
	printf("Enter string and substring:\n");
	char* strMain = (char*)malloc(sizeof(char) * SIZE);
	char* strSub = (char*)malloc(sizeof(char) * SIZE);
	scanf("%s", strMain);
	scanf("%s", strSub);

	int lengthMain = strlen(strMain);
	int lengthSub = strlen(strSub);
	int count = 0;
	for (int i = 0; i < lengthMain - lengthSub + 1; ++i)
	{
		if (strMain[i] == strSub[0])
		{
			int check = 1;
			int continuationI = i + 1;
			for (int j = 1; j < lengthSub; ++j)
			{
				if (strSub[j] == strMain[continuationI])
				{
					++check;
				}
				else
				{
					break;
				}

				++continuationI;
			}

			if (check == lengthSub)
			{
				++count;
			}
		}
	}
	printf("Number of occurrences of a substring in a string = ");
	printf("%d", count);
	free(strMain);
	free(strSub);
}