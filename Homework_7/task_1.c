#include "../library/commonUtils/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const VARIANTSNUMBER = 3;

void getWorksOwners(Graph* homework, int* homeworkOriginalOwners, int numberOfStudents)
{
    for (int i = 0; i < VARIANTSNUMBER + 1; ++i) {
        homeworkOriginalOwners[i] = i;
    }
    for (int i = VARIANTSNUMBER + 1; i < numberOfStudents + 1; ++i) {
        int index = 0;
        while (index < VARIANTSNUMBER + 1 && !isConnected(i, index, homework)) {
            ++index;
        }
        homeworkOriginalOwners[i] = index;
    }
}

void printStudentsVariants(int* homeworkOriginalOwners, int numberOfStudents)
{
    for (int i = 1; i < numberOfStudents + 1; ++i) {
        if (homeworkOriginalOwners[i] == 0) {
            printf("%d student did not pass the work\n", i);
        } else {
            printf("%d student has %d variant\n", i, homeworkOriginalOwners[i]);
        }
    }
}

void fillStudentRegister(Edge** students, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents - VARIANTSNUMBER; ++i) {
        printf("Enter student number and \n "
               "the number of the student from which he wrote off: ");
        int studentNumber = 0;
        int sourceStudentNumber = 0;
        scanf("%d %d", &studentNumber, &sourceStudentNumber);
        if (sourceStudentNumber == -1) {
            students[i] = createEdge(0, studentNumber, 1, false);
        } else {
            students[i] = createEdge(sourceStudentNumber, studentNumber, 1, false);
        }
    }
}

int main()
{
    int numberOfStudents = 0;
    printf("Enter number of students: ");
    scanf("%d", &numberOfStudents);

    Edge** students = (Edge**)malloc((numberOfStudents - VARIANTSNUMBER) * sizeof(Edge*));
    fillStudentRegister(students, numberOfStudents);

    Graph* homework = createGraph(numberOfStudents - VARIANTSNUMBER, numberOfStudents + 1, students);
    int* homeworkOriginalOwners = (int*)malloc((numberOfStudents + 1) * sizeof(int));
    getWorksOwners(homework, homeworkOriginalOwners, numberOfStudents);
    printStudentsVariants(homeworkOriginalOwners, numberOfStudents);

    for (int i = VARIANTSNUMBER + 1; i < numberOfStudents - VARIANTSNUMBER; ++i) {
        free(students[i]);
    }
    free(students);
    free(homeworkOriginalOwners);
    destroyGraph(homework);
    return 0;
}
