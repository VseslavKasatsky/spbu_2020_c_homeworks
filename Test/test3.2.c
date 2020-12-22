#include "../library/commonUtils/priorityQueue.h"
#include <stdio.h>

int main()
{
    PriorityQueue* queue = createPriorityQueue();
    enqueue(queue, 1, 10);
    printQueue(queue);
    enqueue(queue, 2, 7);
    printQueue(queue);
    enqueue(queue, 3, 19);
    printQueue(queue);
    printf("test dequeue: %d \n", dequeue(queue));
    enqueue(queue, 4, 11);
    printQueue(queue);
    enqueue(queue, 50, 1);
    printQueue(queue);
    enqueue(queue, 90, 1);
    printQueue(queue);
    enqueue(queue, 41, 0);
    printQueue(queue);
    enqueue(queue, 52, 0);
    printQueue(queue);
    enqueue(queue, 22, 100);
    printQueue(queue);
    printf("test dequeue: %d \n", dequeue(queue));
    enqueue(queue, 32, 101);
    printQueue(queue);
    printf("test dequeue: %d \n", dequeue(queue));
    enqueue(queue, 55, 0);
    printQueue(queue);
    destroyQueue(queue);
    return 0;
}
