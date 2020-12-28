#ifndef SPBU_2020_C_HOMEWORKS_PRIORITYQUEUE_H
#define SPBU_2020_C_HOMEWORKS_PRIORITYQUEUE_H

#include <stdbool.h>

typedef struct PriorityQueueElement PriorityQueueElement;
typedef struct PriorityQueue PriorityQueue;

PriorityQueue* createPriorityQueue();
PriorityQueueElement* createQueueElement(int value, int priorityValue);

bool enqueue(PriorityQueue* queue, int value, int priorityValue);

int dequeue(PriorityQueue* queue);

void printQueue(PriorityQueue* queue);
void destroyQueue(PriorityQueue* queue);

#endif //SPBU_2020_C_HOMEWORKS_PRIORITYQUEUE_H
