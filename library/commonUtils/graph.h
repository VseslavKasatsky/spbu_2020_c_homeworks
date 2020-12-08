#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
#include <stdbool.h>

typedef struct Graph Graph;
typedef struct Edge Edge;

Graph* createGraph(int countEdges, int countVertex, Edge** edges);
Edge* createEdge(int start, int end, int weight, bool oriented);

void destroyGraph(Graph* graph);

bool depthFirstSearch(Graph* graph, int currentVertex, int* vertexState);
bool isConnected(int fromVertex, int toVertex, Graph* graph);
bool isCycled(Graph* graph);

Graph* createIncidentalGraph(int countEdges, int countVertex, Edge** edges);
void getVertexImposibleToCome(Graph* graph, int vertexNumber, bool* arrayOfVertex);
#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
