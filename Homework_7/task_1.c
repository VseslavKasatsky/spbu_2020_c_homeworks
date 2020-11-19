#include "../library/commonUtils/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getWorksOwners(Graph* homework, int* homeworkOriginalOwners, int numberOfStudents)
{
    bool* connectedTestWorks = (bool*)malloc((numberOfStudents + 1) * sizeof(bool));
    for (int i = 0; i < 4; ++i) {
        memset(connectedTestWorks, false, ((numberOfStudents + 1) * sizeof(bool)));
        pushConnectedVertexToArray(homework, i, connectedTestWorks);
        for (int j = 1; j < numberOfStudents + 1; ++j) {
            if (connectedTestWorks[j]) {
                homeworkOriginalOwners[j] = i;
            }
        }
    }
    free(connectedTestWorks);
}

void fillArrayOfEdges(Edge** students, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; ++i) {
        printf("Enter student number and \n "
               "the number of the student from which he wrote off: ");
        int studentNumber = 0;
        int sourceStudentNumber = 0;
        scanf("%d %d", &studentNumber, &sourceStudentNumber);
        if (sourceStudentNumber == -1) {
            sourceStudentNumber = 0;
        }
        students[i] = createEdge(sourceStudentNumber, studentNumber, 1, true);
    }
}

int main()
{
    int numberOfStudents = 0;
    printf("Enter number of students: ");
    scanf("%d", &numberOfStudents);

    Edge** students = createEdgeArray(numberOfStudents);
    fillArrayOfEdges(students, numberOfStudents);

    Graph* homework = createGraph(numberOfStudents, numberOfStudents + 1, students);
    int* homeworkOriginalOwners = (int*)malloc((numberOfStudents + 1) * sizeof(int));
    getWorksOwners(homework, homeworkOriginalOwners, numberOfStudents);

    for (int i = 1; i < numberOfStudents + 1; ++i) {
        if (homeworkOriginalOwners[i] == 0) {
            printf("%d student did not pass the work\n", i);
        } else {
            printf("%d student has %d variant\n", i, homeworkOriginalOwners[i]);
        }
    }

    free(homeworkOriginalOwners);
    destroyEdgeArray(students, numberOfStudents);
    destroyGraph(homework);
    return 0;
}
