#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int const DIGIT_RANGE = 10;
int get_unique_number(bool* digital_array)
{
    int unique_number = 0;
    srand(time(NULL));
    do {
        unique_number = rand() % 10;
    } while (digital_array[unique_number]);
    return unique_number;
}
void fill_with_random_numbers(int* random_numbers, int digital_range)
{
    bool digital_array[DIGIT_RANGE] = { false };
    for (int i = 0; i < digital_range; ++i) {
        random_numbers[i] = get_unique_number((bool*)&digital_array);
        digital_array[random_numbers[i]] = true;
    }
}
void get_user_guess(int* user_numbers, int digital_range)
{
    int entered_number = 0, digit_count = 0;
    do {
        digit_count = 0;
        printf("Enter %d-digit number: YOUR GUESS: ", digital_range);
        scanf("%d", &entered_number);
        int entered_number_copy = entered_number;
        while (entered_number_copy > 0) {
            entered_number_copy /= 10;
            digit_count++;
        }

    } while (digit_count != digital_range);
    for (int i = digital_range - 1; i >= 0; --i) {
        user_numbers[i] = entered_number % 10;
        entered_number /= 10; // convert user number to array
    }
}
void count_bull_cow(int* user_numbers, int* random_numbers, int* cow,
    int* bull, int digital_range)
{
    for (int i = 0; i < digital_range; ++i) {
        for (int j = 0; j < digital_range; ++j) {
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
void start_game(int* random_numbers, int digital_range)
{
    bool is_guessed = true;
    int* user_numbers = (int*)malloc(digital_range * sizeof(int));
    while (is_guessed) {
        int cow = 0, bull = 0;
        get_user_guess(user_numbers, digital_range);
        count_bull_cow(user_numbers, random_numbers, &cow, &bull, digital_range);
        if (bull != digital_range) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            is_guessed = false;
        }
    }
    printf("YOU WIN!");
    free(user_numbers);
}
int main()
{
    int digital_range = 0;
    do {
        printf("Enter the length of the number to solve from 4 to 10: ");
        scanf("%d", &digital_range);
    } while (digital_range >= 10 || digital_range < 4);
    int* random_numbers = (int*)malloc(digital_range * sizeof(int));
    fill_with_random_numbers(random_numbers, digital_range);
    start_game(random_numbers, digital_range);
    free(random_numbers);
    return 0;
}