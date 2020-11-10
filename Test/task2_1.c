#include <stdio.h>

int getFibonacciNumber(int number)
{
    int firstNumber = 1;
    int secondNumber = 0;
    for (int i = 0; i < number; ++i) {
        firstNumber += secondNumber;
        secondNumber = firstNumber - secondNumber;
    }
    return secondNumber;
}

int main()
{
    printf("Enter number of Fibonacci number: ");
    int number = 0;
    scanf("%d", &number);
    int fibonacciNumber = getFibonacciNumber(number);
    printf("%d Fibonacci number is %d", number, fibonacciNumber);
    return 0;
}
