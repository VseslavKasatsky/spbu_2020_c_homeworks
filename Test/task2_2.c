#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const DATE_SIZE = 8;

bool getDate(int* date, FILE* file)
{
    memset(date, 0, DATE_SIZE * sizeof(int));
    char buffer = 0;
    int i = 0;
    while (buffer != ' ') {
        buffer = fgetc(file);
        if (buffer == EOF) {
            return false;
        }
        if ((buffer >= '0') && (buffer <= '9')) {
            date[i] = buffer - '0';
            ++i;
            if(i==9)
            {
                return false;
            }
        }
    }
    return true;
}

void arrayCopy(int* arrayFrom, int* arrayTo)
{
    for (int i = 0; i < 8; ++i) {
        arrayTo[i] = arrayFrom[i];
    }
}

bool compareDate(int* date, int* minimumDate)
{
    int dateBuffer = 0;
    int minimumDateBuffer = 0;
    if ((date[0] == 0&& date[1] ==0) || (date[2] == 0 && date[3] == 0) || (date[4] == 0 && date[5] == 0 && date[6] == 0 && date[7] == 0)) {
        return false;
    }
    for (int i = 4; i < 8; ++i) {
        dateBuffer = dateBuffer * 10 + date[i];
        minimumDateBuffer = minimumDateBuffer * 10 + minimumDate[i];
    }
    if (dateBuffer == minimumDateBuffer) {
        for (int i = 2; i < 4; ++i) {
            dateBuffer = dateBuffer * 10 + date[i];
            minimumDateBuffer = minimumDateBuffer * 10 + minimumDate[i];
        }
        if (dateBuffer == minimumDateBuffer) {
            for (int i = 0; i < 2; ++i) {
                dateBuffer = dateBuffer * 10 + date[i];
                minimumDateBuffer = minimumDateBuffer * 10 + minimumDate[i];
            }
            if (dateBuffer < minimumDateBuffer) {
                arrayCopy(date, minimumDate);
                return true;
            }
            return false;
        }
        if (dateBuffer < minimumDateBuffer) {
            arrayCopy(date, minimumDate);
            return true;
        }
        return false;
    }
    if (dateBuffer < minimumDateBuffer) {
        arrayCopy(date, minimumDate);
        return true;
    }
    return false;
}

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("ERROR! The program could not open the file!");
        return -1;
    }
    int* date = (int*)malloc(DATE_SIZE * sizeof(int));
    int* minimumDate = (int*)malloc(DATE_SIZE * sizeof(int));
    memset(minimumDate, 9, DATE_SIZE * sizeof(int));

    bool flag = getDate(date, file);
    while (flag) {
        compareDate(date, minimumDate);
        flag = getDate(date, file);
    }
    printf("Minimum date is ");
    for (int i = 0; i < 8; ++i) {
        if (i == 2 || i == 4) {
            printf(".");
        }
        printf("%d", minimumDate[i]);
    }
    free(date);
    free(minimumDate);
    fclose(file);
    return 0;
}
