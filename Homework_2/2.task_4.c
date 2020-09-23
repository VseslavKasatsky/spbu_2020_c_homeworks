#include <stdio.h>
int const DIGIT_AMOUNT = 10;
long long int input_digit_frequency(long long int number, int* digit_freq)
{
    for (int i = 0; i < DIGIT_AMOUNT; ++i) {
        digit_freq[i] = 0;
    }
    printf("Enter the number: ");
    scanf("%lld", &number);
    while (number > 0) {
        digit_freq[number % 10]++; // Array of digits included in the number
        number /= 10;
    }
    return (number);
}
void output_smallest_number(long long int number, int* digit_freq)
{
    if (digit_freq[0] != 0) { // checking the first digit of a number
        int i = 1;
        while (number == 0) {
            if (digit_freq[i] != 0) {
                number = i;
                digit_freq[i]--;
            }
            i++;
        }
    }
    for (int i = 0; i < DIGIT_AMOUNT; ++i) {
        while (digit_freq[i] != 0) {
            number = number * 10 + i; // drawing up a number
            digit_freq[i]--;
        }
    }
    printf("The smallest number of composed digits of the entered number: %lld",
        number);
}
int main()
{
    long long int number = 0;
    int digit_freq[DIGIT_AMOUNT];
    int* link = digit_freq;
    input_digit_frequency(number, link);
    output_smallest_number(number, link);
}
