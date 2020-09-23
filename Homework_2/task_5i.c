#include <stdio.h>
int factorial(int number)
{
    if (number < 0) {
        return 0;
    }
    if (number >= 0) {
        int result = 1;
        for (int i = 1; i <= number; ++i) {
            result = result * i;
        }
        return result;
    }
}
int main()
{
    int number = 0;
    printf("Enter number for factorial: ");
    scanf("%d", &number);
    printf("Factorial: %d", factorial(number));
    return 0;
}