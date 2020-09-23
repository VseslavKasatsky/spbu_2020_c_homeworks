#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number_arr[4] = { 0 }, check_arr[4], check = 0;
    bool flag = 1;
    for (int i = 0; i < 4; ++i) {
        srand(time(NULL));
        while (i < 4) {
            number_arr[i] = rand() % 10;
            for (int j = 0; j < i; ++j) {
                if (number_arr[i] == number_arr[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                // printf("%d", number_arr[i]); - answer
                i++;
            }
            flag = 1;
        }
    }

    while (flag) {
        int cow = 0, bull = 0;
        printf("YOUR GUESS: ");
        scanf("%d", &check);
        for (int i = 3; i >= 0; --i) {
            check_arr[i] = check % 10;
            check /= 10;
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (check_arr[i] == number_arr[j]) {
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
    return 0;
}
