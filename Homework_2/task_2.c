#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int const DIGITAL_RANGE = 4; //The length of the guessed sequential
void generating_random_number(int* random_number_array)
{
    bool flag = 1;
    for (int i = 0; i < DIGITAL_RANGE; ++i) {
        srand(time(NULL));
        while (i < DIGITAL_RANGE) {
            random_number_array[i] = rand() % 10;
            for (int j = 0; j < i; ++j) {
                if (random_number_array[i] == random_number_array[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("%d", random_number_array[i]);
                i++;
            }
            flag = 1;
        }
    }
}
void start_game(int* random_number_array)
{
    bool flag = 1;
    int user_number_array[DIGITAL_RANGE] = { 0 }, user_number = 0;
    while (flag) {
        int cow = 0, bull = 0;
        printf("YOUR GUESS: ");
        scanf("%d", &user_number);
        for (int i = DIGITAL_RANGE - 1; i >= 0; --i) {
            user_number_array[i] = user_number % 10;
            user_number /= 10; //convert user number to array
        }
        for (int i = 0; i < DIGITAL_RANGE; ++i) {
            for (int j = 0; j < DIGITAL_RANGE; ++j) {
                if (random_number_array[i] == user_number_array[j]) {
                    if (i == j) {
                        bull++;
                    } else {
                        cow++;
                    }
                }
            }
        }
        if (bull != DIGITAL_RANGE) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            flag = 0;
        }
    }
    printf("YOU WIN!");
}
int main()
{
    int random_number_array[DIGITAL_RANGE];
    generating_random_number((int*)&random_number_array);
    start_game((int*)&random_number_array);
    return 0;
}