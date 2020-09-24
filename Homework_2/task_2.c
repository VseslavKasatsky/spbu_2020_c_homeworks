#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_with_random_numbers(int* random_number, int DIGITAL_RANGE)
{
    bool isEqual = true;
    for (int i = 0; i < DIGITAL_RANGE; ++i) {
        srand(time(NULL));
        while (i < DIGITAL_RANGE) {
            random_number[i] = rand() % 10;
            for (int j = 0; j < i; ++j) {
                if (random_number[i] == random_number[j]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                // printf("%d", random_number[i]); - answer
                i++;
            }
            isEqual = true;
        }
    }
}
void get_user_guesses(int* user_number, int DIGITAL_RANGE)
{
    int entered_number = 0;
    printf("YOUR GUESS: ");
    scanf_s("%d", &entered_number);
    for (int i = DIGITAL_RANGE - 1; i >= 0; --i) {
        user_number[i] = entered_number % 10;
        entered_number /= 10; // convert user number to array
    }
}
void count_equal_numbers(int* user_number, int* random_number, int* cow,
    int* bull, int DIGITAL_RANGE)
{
    for (int i = 0; i < DIGITAL_RANGE; ++i) {
        for (int j = 0; j < DIGITAL_RANGE; ++j) {
            if (random_number[i] == user_number[j]) {
                if (i == j) {
                    *bull = *bull + 1;
                } else {
                    *cow = *cow + 1;
                }
            }
        }
    }
}
void start_game(int* random_number, int DIGITAL_RANGE)
{
    bool isGuessed = true;
    int* user_number = (int*)malloc(DIGITAL_RANGE * sizeof(int));
    while (isGuessed) {
        int cow = 0, bull = 0;
        get_user_guesses(user_number, DIGITAL_RANGE);
        count_equal_numbers(user_number, random_number, &cow, &bull, DIGITAL_RANGE);
        if (bull != DIGITAL_RANGE) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            isGuessed = false;
        }
    }
    printf("YOU WIN!");
    free(user_number);
}
int main()
{
    int DIGITAL_RANGE = 0;
    printf("Enter the length of the number to solve: ");
    scanf_s("%d", &DIGITAL_RANGE);
    int* random_number = (int*)malloc(DIGITAL_RANGE * sizeof(int));
    fill_with_random_numbers(random_number, DIGITAL_RANGE);
    start_game(random_number, DIGITAL_RANGE);
    free(random_number);
    return 0;
}