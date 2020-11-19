#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
#include <stdbool.h>

typedef struct Graph Graph;
typedef struct Edge Edge;

Graph* createGraph(int countEdges, int countVertex, Edge** edges);
Edge* createEdge(int start, int end, int weight, bool oriented);
Edge** createEdgeArray(int amount);

void destroyGraph(Graph* graph);
void destroyEdgeArray(Edge** edgeArray, int amount);
void pushConnectedVertexToArray(Graph* graph, int vertex, bool* isConnected);

bool depthFirstSearch(Graph* graph, int currentVertex, int* vertexState);
bool isConnected(int fromVertex, int toVertex, Graph* graph);
bool isCycled(Graph* graph);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_GRAPH_H_
