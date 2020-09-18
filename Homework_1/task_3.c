#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "BlueYellgreenBlueowblueYelBluelowBluePinblkJetBlue";
	char search[] = "Blue";
	int amount = 0, i = 0, length = sizeof(search) - 1;
	char* p = strstr(str, search);
	while (1)
	{
		char* p = strstr(str, search);
		if (p == NULL)
		{
			break;
		}
		for (i = 0; i < p - str + 1; i++)
		{
			str[i] = '/0';
		}
		amount++;
	}
	printf("%d", amount);
	return 0;
}