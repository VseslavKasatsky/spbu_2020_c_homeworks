#include <stdbool.h>
#include <stdio.h>
#define SIZEOFMANTISSA 52
#define SIZEOFEXPONENT 11

int getExponent(unsigned long long bits)
{
    bool binaryExponent[SIZEOFEXPONENT] = { 0 };
    bits >>= SIZEOFMANTISSA;
    for (int i = SIZEOFEXPONENT; i > 0; --i) {
        binaryExponent[i - 1] = (bits & 1);
        bits >>= 1;
    }
    int exponent = 0;
    for (int i = 0; i < SIZEOFEXPONENT; ++i) {
        exponent += binaryExponent[i] * (1 << (SIZEOFEXPONENT - 1 - i));
    }
    return exponent - 1023;
}

double getMantissa(unsigned long long bits)
{
    bool binaryMantissa[SIZEOFMANTISSA + 1] = { 0 };
    for (int i = SIZEOFMANTISSA + 1; i > 1; --i) {
        binaryMantissa[i - 1] = (bits & 1);
        bits >>= 1;
    }
    binaryMantissa[0] = 1;
    double mantissa = 0;
    long long int powerOfTwo = 1;
    for (int i = 0; i < SIZEOFMANTISSA + 1; ++i) {
        mantissa = mantissa + ((long double)binaryMantissa[i] / powerOfTwo);
        powerOfTwo *= 2;
    }
    return mantissa;
}

void printInExponentialForm(unsigned long long bits, double number)
{
    double mantissa = getMantissa(bits);
    int exponent = getExponent(bits);
    short sign = (bits >> SIZEOFMANTISSA + SIZEOFEXPONENT) ? -1 : 1;
    printf("%f*2^{%d}", sign * mantissa, exponent);
}

int main()
{
    double number = 0;
    printf("Enter number:");
    scanf("%lf", &number);
    if (number == 0) {
        printf("%f*2^{%d}", 0.0, 0);
        return 0;
    }
    unsigned long long bits = *(unsigned long long*)&number;
    printInExponentialForm(bits, number);
    return 0;
}