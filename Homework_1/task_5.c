#include <stdio.h>
#include <stdlib.h>

int const SIZE = 9;

int helper(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int i = 0, answer = 0, array[SIZE] = {0};
  for (i = 0; i < SIZE; i++) {
	scanf("%d", &array[i]);
  }
  qsort(array, SIZE, sizeof(int), helper);
  for (i = SIZE - 1; i > 0; i--) {
	if (array[i] == array[i - 1]) {
	  answer = array[i];
	  break;
	}
  }
  printf("%d", answer);
  return 0;
}