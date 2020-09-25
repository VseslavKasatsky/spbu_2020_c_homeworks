#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_with_random_numbers(int* random_numbers, int DigitalRange)
{
    for (int i = 0; i < DigitalRange; ++i) {
        srand(time(NULL));
        while (i < DigitalRange) {
          bool isEqual = true;
          random_numbers[i] = rand() % 10;
            for (int j = 0; j < i; ++j) {
                if (random_numbers[i] == random_numbers[j]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                i++;
            }
            isEqual = true;
        }
    }
}
void get_user_guess(int* user_numbers, int DigitalRange)
{
    int entered_number = 0;
    bool isCorrect=false;
    printf("YOUR GUESS: ");
    do {
      int digit_count=0;
      scanf("%d", &entered_number);

    for (int i = DigitalRange - 1; i >= 0; --i) {
        user_numbers[i] = entered_number % 10;
        if(entered_number>0)
        {
          digit_count++;
        }
        entered_number /= 10; // convert user number to array
    }
    if(digit_count != DigitalRange)
    {
      isCorrect=true;
    }
    }
    while(isCorrect);
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
  bool isCorrect=false;
    printf("Enter the length of the number to solve: ");
    do {
       isCorrect=false;
      scanf("%d", &DigitalRange);
      if(DigitalRange>=10 || DigitalRange<4)
      {
        printf("Please enter another number: ");
        isCorrect=true;
      }
    }
    while(isCorrect);
    int* random_numbers = (int*)malloc(DigitalRange * sizeof(int));
    fill_with_random_numbers(random_numbers, DigitalRange);
    start_game(random_numbers, DigitalRange);
    free(random_numbers);
    return 0;
}