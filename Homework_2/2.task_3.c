#include <stdio.h>
const int N = 11;

int main() {
  int array[N], counter_start = 0, counter_end = N - 1, vault = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &array[i]);
  }
  for (; counter_start < counter_end; ++counter_start) {
    while (array[counter_end] == 0) {
      counter_end--;
    }
    if (array[counter_start] == 0) {
      vault = array[counter_start];
      array[counter_start] = array[counter_end];
      array[counter_end] = vault;
      counter_end--;
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%d ", array[i]);
  }
}