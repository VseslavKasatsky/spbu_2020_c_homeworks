#include <stdbool.h>
#include <stdio.h>

int main()
{
    int number = 0;
    printf("Enter the number");
    scanf("%d", &number);
    printf("Prime numbers: ");
    for (int i = 2; i < number; ++i) {
        bool flag = 1;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", i);
        }
    }
    return 0;
}