#include <stdbool.h>
#include <stdio.h>

void getInBinary(int number, bool binaryNumber[])
{
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        binaryNumber[i] = (number & 1) == 1;
        number >>= 1;
    }
}

void getBinarySum(bool binaryFirstNumber[], bool binarySecondNumber[], bool binarySum[])
{
    bool overFlow = 0;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        int subSum = 0;
        subSum = binaryFirstNumber[i] + binarySecondNumber[i] + overFlow;
        binarySum[i] = subSum % 2;
        overFlow = subSum / 2;
    }
}

int getInDecimal(bool binarySum[])
{
    int value = 0;
    int powerOfTwo = 1;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        if (binarySum[i]) {
            value += powerOfTwo;
        }
        powerOfTwo *= 2;
    }
    return value;
}

int main()
{
    printf("Enter first number:");
    int firstNumber = 0;
    scanf("%d", &firstNumber);
    printf("Enter second number:");
    int secondNumber = 0;
    scanf("%d", &secondNumber);
    bool binaryFirstNumber[sizeof(int) * 8] = { 0 };
    getInBinary(firstNumber, binaryFirstNumber);
    bool binarySecondNumber[sizeof(int) * 8] = { 0 };
    getInBinary(secondNumber, binarySecondNumber);
    bool binarySum[sizeof(int) * 8] = { 0 };
    getBinarySum(binaryFirstNumber, binarySecondNumber, binarySum);
    printf("(Sum in decimal algorithm) First number + Second number = %d \n", firstNumber + secondNumber);
    printf("(Sum in binary algorithm) First number + Second number = %d \n", getInDecimal(binarySum));
    return 0;
}