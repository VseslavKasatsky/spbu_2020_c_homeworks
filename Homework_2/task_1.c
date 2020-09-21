#include <stdio.h>
#include <stdlib.h>

int size = 0;
int* array = 0;
int* values = NULL;
void print()
{
	printf("%d", values[0]);
	for (int i = 1; i < size; i++)
		printf("+%d", values[i]);
	printf("\n");
}

void recursion(int left_sum, int last_term)
{
	if (left_sum == 0)
		print();
	for (int i = last_term; i <= left_sum; i++)
	{
		size++;
		array = (int*)realloc(values, sizeof(int) * (size));
		values = array;
		values[size-1] = i;
		recursion(left_sum - i, i);
		size--;
	}
}
int main()
{
	int number;
	scanf_s("%d", &number);
	recursion(number, 1);
	free(values);
	return 0;
}