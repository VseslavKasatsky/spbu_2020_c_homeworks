#include <stdio.h>
#include <stdlib.h>

void scanStudentsList(int* studentList, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; ++i) {
        int variantNumber = 0;
        int studentNumber = 0;
        printf("Enter student number and variant: ");
        scanf("%d%d", &studentNumber, &variantNumber);
        studentList[studentNumber - 1] = variantNumber;
    }
}

void getStudentsVariantNumber(int* studentList, int numberOfStudents)
{
    for (int i = 3; i < numberOfStudents; ++i) {
        while (studentList[i] > 3) {
            studentList[i] = studentList[studentList[i] - 1];
        }
    }
}

void printStudentVariantNumber(int* studentList, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; ++i) {
        if (studentList[i] != -1) {
            printf("%d.student - %d variant\n", i + 1, studentList[i]);
        } else {
            printf("%d.student - did not pass\n", i + 1);
        }
    }
}

int main()
{
    int numberOfStudents = 0;
    printf("Enter number of students: ");
    scanf("%d", &numberOfStudents);
    int* studentsList = (int*)malloc(numberOfStudents * sizeof(int));
    scanStudentsList(studentsList, numberOfStudents);
    getStudentsVariantNumber(studentsList, numberOfStudents);
    printStudentVariantNumber(studentsList, numberOfStudents);
    free(studentsList);
    return 0;
}
