#include "test1_2.h"
#include <stdio.h>
#include <stdlib.h>
struct ListComplexElement {
    int realNumber;
    int imaginaryNumber;
};
ListComplexElement* createListElement(int imaginary, int real)
{
    ListComplexElement* element = malloc(sizeof(ListComplexElement));
    element->imaginaryNumber = imaginary;
    element->realNumber = real;
    return element;
}
ListComplexElement* subtract(ListComplexElement* firstElement, ListComplexElement* secondElement)
{
    ListComplexElement* subtractionResult = malloc(sizeof(ListComplexElement));
    subtractionResult->realNumber = firstElement->realNumber - secondElement->realNumber;
    subtractionResult->imaginaryNumber = firstElement->imaginaryNumber - secondElement->imaginaryNumber;
    return subtractionResult;
}
ListComplexElement* sum(ListComplexElement* firstElement, ListComplexElement* secondElement)
{
    ListComplexElement* sumResult = malloc(sizeof(ListComplexElement));
    sumResult->realNumber = firstElement->realNumber + secondElement->realNumber;
    sumResult->imaginaryNumber = firstElement->imaginaryNumber + secondElement->imaginaryNumber;
    return sumResult;
}
ListComplexElement* multiplication(ListComplexElement* firstElement, ListComplexElement* secondElement)
{
    ListComplexElement* multiplicationResult = malloc(sizeof(ListComplexElement));
    multiplicationResult->realNumber = firstElement->realNumber * secondElement->realNumber - firstElement->imaginaryNumber * secondElement->imaginaryNumber;
    multiplicationResult->imaginaryNumber = firstElement->realNumber * secondElement->imaginaryNumber + firstElement->imaginaryNumber * secondElement->realNumber;
    return multiplicationResult;
}
ListComplexElement* division(ListComplexElement* firstElement, ListComplexElement* secondElement)
{
    ListComplexElement* divisionResult = malloc(sizeof(ListComplexElement));
    ListComplexElement* numerator = malloc(sizeof(ListComplexElement));
    ListComplexElement* denominator = malloc(sizeof(ListComplexElement));
    ListComplexElement* secondElementCopy = malloc(sizeof(ListComplexElement));
    secondElementCopy->imaginaryNumber = secondElement->imaginaryNumber * -1;
    secondElementCopy->realNumber = secondElement->realNumber;
    numerator = multiplication(firstElement, secondElementCopy);
    denominator = multiplication(secondElement, secondElementCopy);
    divisionResult->realNumber = numerator->realNumber / denominator->realNumber;
    divisionResult->imaginaryNumber = numerator->imaginaryNumber / denominator->realNumber;
    free(numerator);
    free(denominator);
    free(secondElementCopy);
    return divisionResult;
}
