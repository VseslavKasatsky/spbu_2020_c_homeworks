#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int const DIGITS = 10;
int getUniqueNumber(bool* digitalArray)
{
    int uniqueNumber = 0;
    srand(time(NULL));
    do {
        uniqueNumber = rand() % 10;
    } while (digitalArray[uniqueNumber]);
    return uniqueNumber;
}
void fillWithRandomNumbers(int* randomNumbers, int digitalRange)
{
    bool* digitalArray = malloc(DIGITS * sizeof(bool));
    memset(digitalArray, false, DIGITS);
    for (int i = 0; i < digitalRange; ++i) {
        randomNumbers[i] = getUniqueNumber(digitalArray);
        digitalArray[randomNumbers[i]] = true;
    }
    free(digitalArray);
}
void getUserGuess(int* userNumbers, int digitalRange)
{
    int enteredNumber = 0, digitCount = 0;
    char enteredNumberCopy[12];
    do {
        digitCount = 0;
        printf("Enter %d-digit number. YOUR GUESS: ", digitalRange);
        fgets(enteredNumberCopy, 12 * sizeof(char), stdin);
        while (enteredNumberCopy[digitCount] != '\0') {
            digitCount++;
        }
    } while (digitCount - 1 != digitalRange);
    for (int i = 0; i < digitalRange; ++i) {
        userNumbers[i] = enteredNumberCopy[i] - '0'; // convert user number to array
    }
}
void countBullCow(int* userNumbers, int* randomNumbers, int* cow,
    int* bull, int digitalRange)
{
    for (int i = 0; i < digitalRange; ++i) {
        for (int j = 0; j < digitalRange; ++j) {
            if (randomNumbers[i] == userNumbers[j]) {
                if (i == j) {
                    *bull += 1;
                } else {
                    *cow += 1;
                }
            }
        }
    }
}
void startGame(int* randomNumbers, int digitalRange)
{
    bool isGuessed = true;
    int* userNumbers = (int*)malloc(digitalRange * sizeof(int));
    memset(userNumbers, 0, digitalRange);
    while (isGuessed) {
        int cow = 0, bull = 0;
        getUserGuess(userNumbers, digitalRange);
        countBullCow(userNumbers, randomNumbers, &cow, &bull, digitalRange);
        if (bull != digitalRange) {
            printf("%d bull %d cow \n", bull, cow);
        } else {
            isGuessed = false;
        }
    }
    printf("YOU WIN!");
    free(userNumbers);
}
int main()
{
    int digitalRange = 0;
    do {
        printf("Enter the length of the number to solve from 4 to 10: ");
        scanf("%d", &digitalRange);
    } while (digitalRange > 10 || digitalRange < 4);
    int* randomNumbers = (int*)malloc(digitalRange * sizeof(int));
    memset(randomNumbers, 0, digitalRange);
    fillWithRandomNumbers(randomNumbers, digitalRange);
    startGame(randomNumbers, digitalRange);
    free(randomNumbers);
    return 0;
}