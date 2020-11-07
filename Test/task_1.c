#include <stdio.h>
#include <stdlib.h>

int arraySort(const void* b, const void* a)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int subjects = 0;
    printf("Enter the amount of subjects:");
    scanf("%d", &subjects);
    int* vasyaSummary = malloc(subjects * sizeof(int));
    int* petyaSummary = malloc(subjects * sizeof(int));
    printf("Enter Vasya summary with %d elements", subjects);
    for (int i = 0; i < subjects; ++i) {
        scanf("%d", &vasyaSummary[i]);
    }
    printf("Enter Petya summary with %d elements", subjects);
    for (int i = 0; i < subjects; ++i) {
        scanf("%d", &petyaSummary[i]);
    }
    int* summary = malloc(subjects * 2 * sizeof(int));
    for (int i = 0; i < subjects; ++i) {
        summary[i] = vasyaSummary[i];
        summary[i + subjects] = petyaSummary[i];
    }
    qsort(summary, 2 * subjects, sizeof(int), arraySort);
    for (int i = 0; i < 2 * subjects; ++i) {
        printf("%d", summary[i]);
    }
    return 0;
}