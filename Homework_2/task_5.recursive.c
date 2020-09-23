#include <stdio.h>

int factorial(int number)
{
    if (number < 0) {
        return 0;
    }
    if (number == 0) {
        return 1;
    }
    return number * factorial(number - 1);
}
int main()
{
    int number = 0;
    printf("Enter number for factorial: ");
    scanf("%d", &number);
    printf("Factorial: %d", factorial(number));
    return 0;
}
