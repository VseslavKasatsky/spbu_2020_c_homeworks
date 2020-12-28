#include "priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

struct PriorityQueueElement {
    int value;
    int priorityValue;
    struct PriorityQueueElement* next;
};

struct PriorityQueue {
    struct PriorityQueueElement* head;
};

PriorityQueue* createPriorityQueue()
{
    PriorityQueue* queue = malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}

PriorityQueueElement* createQueueElement(int value, int priorityValue)
{
    PriorityQueueElement* element = malloc(sizeof(PriorityQueueElement));
    element->value = value;
    element->priorityValue = priorityValue;
    element->next = NULL;
    return element;
}

bool isEmpty(PriorityQueue* queue)
{
    return queue->head == NULL;
}

bool pushToQueue(PriorityQueue* queue, PriorityQueueElement* element)
{
    PriorityQueueElement* currentElement = queue->head;
    while (currentElement->next != NULL && currentElement->next->priorityValue >= element->priorityValue) {
        currentElement = currentElement->next;
    }
    element->next = currentElement->next;
    currentElement->next = element;
    return true;
}

bool enqueue(PriorityQueue* queue, int value, int priorityValue)
{
    if (isEmpty(queue)) {
        PriorityQueueElement* element = createQueueElement(value, priorityValue);
        queue->head = element;
        return true;
    }
    PriorityQueueElement* element = createQueueElement(value, priorityValue);
    if (queue->head->priorityValue < priorityValue) {
        element->next = queue->head;
        queue->head = element;
        return true;
    }
    return pushToQueue(queue, element);
}

int dequeue(PriorityQueue* queue)
{
    if (isEmpty(queue)) {
        return -1;
    }
    int highestPriorityValue = queue->head->value;
    PriorityQueueElement* element = queue->head;
    queue->head = element->next;
    free(element);
    return highestPriorityValue;
}

void printQueue(PriorityQueue* queue)
{
    printf("START -> ");
    PriorityQueueElement* toPrint = queue->head;
    while (toPrint != NULL) {
        printf("%d[%d] -> ", toPrint->value, toPrint->priorityValue);
        toPrint = toPrint->next;
    }
    printf("END\n");
}

void destroyQueue(PriorityQueue* queue)
{
    PriorityQueueElement* currentElement = queue->head;
    while (currentElement == NULL) {
        PriorityQueueElement* temporaryElement = currentElement;
        currentElement = currentElement->next;
        free(temporaryElement);
    }
    free(queue);
}
