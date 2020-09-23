#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int const DIGITAL_RANGE = 4; //The length of the guessed sequential
void generating_random_number(int* random_number_array)
{
    bool flag = 1;
    for (int i = 0; i < 4; ++i) {
        srand(time(NULL));
        while (i < 4) {
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
    int user_number_array[4] = { 0 }, user_number = 0;
    while (flag) {
        int cow = 0, bull = 0;
        printf("YOUR GUESS: ");
        scanf("%d", &user_number);
        for (int i = 3; i >= 0; --i) {
            user_number_array[i] = user_number % 10;
            user_number /= 10; //convert user number to array
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (random_number_array[i] == user_number_array[j]) {
                    if (i == j) {
                        bull++;
                    } else {
                        cow++;
                    }
                }
            }
        }
        if (bull != 4) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            flag = 0;
        }
    }
    printf("YOU WIN!");
}
int main()
{
    int random_number_array[4];
    int* link_to_random_array = random_number_array;
    generating_random_number(link_to_random_array);
    start_game(link_to_random_array);
    return 0;
}