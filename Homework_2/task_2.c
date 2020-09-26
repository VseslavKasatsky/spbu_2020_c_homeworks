#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_unique_number(bool* digitalArray)
{
    int unique_number = 0;
    srand(time(NULL));
    do {
        unique_number = rand() % 10;
    } while (digitalArray[unique_number]);
    return unique_number;
}
void fill_with_random_numbers(int* random_numbers, int DigitalRange)
{
    bool digitalArray[10] = { false };
    for (int i = 0; i < DigitalRange; ++i) {
        random_numbers[i] = get_unique_number((bool*)&digitalArray);
        digitalArray[random_numbers[i]] = true;
    }
}
void get_user_guess(int* user_numbers, int DigitalRange)
{
    int entered_number = 0, digit_count = 0;
    do {
        digit_count = 0;
        printf("YOUR GUESS: ");
        scanf("%d", &entered_number);

        for (int i = DigitalRange - 1; i >= 0; --i) {
            user_numbers[i] = entered_number % 10;
            if (entered_number > 0) {
                digit_count++;
            }
            entered_number /= 10; // convert user number to array
        }
    } while (digit_count != DigitalRange);
}
void count_bull_cow(int* user_numbers, int* random_numbers, int* cow,
    int* bull, int DigitalRange)
{
    for (int i = 0; i < DigitalRange; ++i) {
        for (int j = 0; j < DigitalRange; ++j) {
            if (random_numbers[i] == user_numbers[j]) {
                if (i == j) {
                    *bull += 1;
                } else {
                    *cow += 1;
                }
            }
        }
    }
}
void start_game(int* random_numbers, int DigitalRange)
{
    bool isGuessed = true;
    int* user_numbers = (int*)malloc(DigitalRange * sizeof(int));
    while (isGuessed) {
        int cow = 0, bull = 0;
        get_user_guess(user_numbers, DigitalRange);
        count_bull_cow(user_numbers, random_numbers, &cow, &bull, DigitalRange);
        if (bull != DigitalRange) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            isGuessed = false;
        }
    }
    printf("YOU WIN!");
    free(user_numbers);
}
int main()
{
    int DigitalRange = 0;
    do {
        printf("Enter the length of the number to solve: ");
        scanf("%d", &DigitalRange);
    } while (DigitalRange >= 10 || DigitalRange < 4);
    int* random_numbers = (int*)malloc(DigitalRange * sizeof(int));
    fill_with_random_numbers(random_numbers, DigitalRange);
    start_game(random_numbers, DigitalRange);
    free(random_numbers);
    return 0;
}