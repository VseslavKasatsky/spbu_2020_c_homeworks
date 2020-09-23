#include <stdio.h>
const int N = 11;

int main()
{
    int array[N], vault = 0;
    for (int i = 0; i < N; ++i) {
        printf("array[%d]=", i);
        scanf("%d", &array[i]);
    }
    for (int counter_start = 0, counter_end = N - 1; counter_start < counter_end; ++counter_start) {
        while (array[counter_end] == 0) {
            counter_end--; //finding a nonzero element at the end
        }
        if (array[counter_start] == 0) { //swap
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