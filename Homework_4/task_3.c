#include <stdbool.h>
#include <stdio.h>
#define SIZEOFINT 32

void getInBinary(int number, bool binaryNumber[])
{
    for (int i = 0; i < SIZEOFINT; ++i) {
        binaryNumber[i] = (number & 1) == 1;
        number >>= 1;
    }
}
void getBinarySum(bool binaryFirstNumber[], bool binarySecondNumber[], bool binarySum[])
{
    bool overFlow = 0;
    for (int i = 0; i < SIZEOFINT; ++i) {
        int subSum = 0;
        subSum = binaryFirstNumber[i] + binarySecondNumber[i] + overFlow;
        switch (subSum) {
        case 0:
            binarySum[i] = 0;
            overFlow = 0;
            break;
        case 1:
            binarySum[i] = 1;
            overFlow = 0;
            break;
        case 2:
            binarySum[i] = 0;
            overFlow = 1;
            break;
        case 3:
            binarySum[i] = 1;
            overFlow = 1;
            break;
        }
    }
}
int getInDecimal(bool binarySum[])
{
    int value = 0;
    int powerOfTwo = 1;
    for (int i = 0; i < SIZEOFINT; ++i) {
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
    bool binaryFirstNumber[SIZEOFINT] = { 0 };
    getInBinary(firstNumber, binaryFirstNumber);
    bool binarySecondNumber[SIZEOFINT] = { 0 };
    getInBinary(secondNumber, binarySecondNumber);
    bool binarySum[SIZEOFINT] = { 0 };
    getBinarySum(binaryFirstNumber, binarySecondNumber, binarySum);
    printf("(Sum in decimal algorithm) First number + Second number = %d \n", firstNumber + secondNumber);
    printf("(Sum in binary algorithm) First number + Second number = %d \n", getInDecimal(binarySum));
    return 0;
}