#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const DATE_SIZE = 10;

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

bool getDate(char* date, FILE* file)
{
    memset(date, 0, DATE_SIZE * sizeof(char));
    char buffer = 0;
    int i = 0;
    while (buffer != ' ') {
        buffer = fgetc(file);
        if (buffer == EOF) {
            return false;
        }
        if (((buffer >= '0') && (buffer <= '9')) || (buffer == '.' && (i == 2 || i == 5))) {
            date[i] = buffer;
            ++i;
            if (i == 10) {
                return true;
            }
        }
    }
    return true;
}

int getYear(char* date)
{
    int year = 0;
    for (int i = 6; i < 10; ++i) {
        year = year * 10 + (date[i] - '0');
    }
    return year;
}

int getMonth(char* date)
{
    int month = 0;
    for (int i = 3; i < 5; ++i) {
        month = month * 10 + (date[i] - '0');
    }
    return month;
}

int getDay(char* date)
{
    int day = 0;
    for (int i = 0; i < 2; ++i) {
        day = day * 10 + (date[i] - '0');
    }
    return day;
}

bool isDate(char* date)
{
    if (date[0] - '0' > 3) {
        return false;
    }
    if (date[0] == 0) {
        return false;
    }
    if (date[3] - '0' > 1) {
        return false;
    }
    return true;
}

Date compareDate(char* date, Date minimumDate)
{
    if (!isDate(date)) {
        return minimumDate;
    }
    Date currentDate = { getYear(date), getMonth(date), getDay(date) };
    if (currentDate.year < minimumDate.year) {
        minimumDate = currentDate;
        return minimumDate;
    }
    if (currentDate.year == minimumDate.year) {
        if (currentDate.month < minimumDate.month) {
            minimumDate = currentDate;
            return minimumDate;
        }
        if (currentDate.month == minimumDate.month) {
            if (currentDate.day < minimumDate.day) {
                minimumDate = currentDate;
                return minimumDate;
            }
        }
    }
    return minimumDate;
}

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("ERROR! The program could not open the file!");
        return -1;
    }
    char* date = (char*)malloc(DATE_SIZE * sizeof(char));
    Date minimumDate = { 9999, 99, 99 };
    bool flag = getDate(date, file);
    while (flag) {
        minimumDate = compareDate(date, minimumDate);
        flag = getDate(date, file);
    }
    printf("Minimum date is %d.%d.%d ", minimumDate.day, minimumDate.month, minimumDate.year);
    free(date);
    fclose(file);
    return 0;
}
