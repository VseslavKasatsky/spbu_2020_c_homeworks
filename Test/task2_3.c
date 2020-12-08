#include "../library/commonUtils/graph.h"
#include <stdio.h>
#include <stdlib.h>

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
}