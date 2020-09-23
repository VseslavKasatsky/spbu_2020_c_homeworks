#include <stdio.h>
int const DIGIT_AMOUNT = 10;
int main()
{
    long long int number = 0;
    int array[DIGIT_AMOUNT];
    for (int i = 0; i < DIGIT_AMOUNT; ++i) {
        array[i] = 0;
    }
    scanf("%I64d", &number);
    while (number > 0) {
        array[number % 10]++; //Array of digits included in the number
        number = number / 10;
    }
    if (array[0] != 0) { //checking the first digit of a number
        int i = 0;
        while (number == 0) {
            if (array[i] != 0) {
                number = i;
                array[i]--;
                i++;
            }
        }
    }
    for (int i = 0; i < DIGIT_AMOUNT; i++) {
        while (array[i] != 0) {
            number = number * 10 + i; //drawing up a number
            array[i]--;
        }
    }
    printf("%I64d", number);
}
