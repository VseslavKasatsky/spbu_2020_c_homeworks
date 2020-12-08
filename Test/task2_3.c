#include "../library/commonUtils/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Enter number of vertex: ");
    int vertexNumber = 0;
    scanf("%d", &vertexNumber);

    printf("Enter number of edges: ");
    int edgesNumber = 0;
    scanf("%d", &edgesNumber);
    Edge** edges = (Edge**)malloc(edgesNumber * sizeof(Edge*));
    for (int i = 0; i < edgesNumber; ++i) {
        printf("Enter start and end vertex in edge: ");
        int startVertex = 0;
        int endVertex = 0;
        scanf("%d", &startVertex);
        scanf("%d", &endVertex);
        edges[i] = createEdge(startVertex, endVertex, 1, true);
    }
    Graph* graph = createIncidentalGraph(edgesNumber, vertexNumber, edges);

    printf("Enter the vertex for which to search for vertices from which it is impossible to come to the given: ");
    int givenVertex = 0;
    scanf("%d", &givenVertex);

    bool* vertexArray = (bool*)malloc((vertexNumber + 1) * sizeof(bool));
    memset(vertexArray, 0, (vertexNumber + 1) * sizeof(bool));
    getConnectedVertexArray(graph, givenVertex, vertexArray);

    printf("Given vertex is not connected to vertices with the following numbers: ");
    for (int i = 1; i < vertexNumber + 1; ++i) {
        if (vertexArray[i]) {
            printf("%d", i);
        }
    }

    for (int i = 0; i < edgesNumber; ++i) {
        free(edges[i]);
    }
    free(edges);
    free(vertexArray);
    destroyIncidentalGraph(graph);
}