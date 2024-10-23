#include "queue.h"
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

queueNode_t* createNode(int element)
{
    queueNode_t* node = (queueNode_t*)malloc(sizeof(queueNode_t));

    node->element = element;
    node->next = NULL;

    return node;
}

void initializeQueue(queue_t* queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

int isEmpty(queue_t* queue)
{
    if (queue->head == NULL || queue->tail == NULL)
        return 1;
    return 0;
}

int enqueue(queue_t* queue, int element)
{
    queueNode_t* node = createNode(element);

    // In case mallocs go wrong
    if (!node)
        return 0;

    // If it is the first element, head and tail are equal
    if (isEmpty(queue))
    {
        queue->head = node;
        queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }

    return 1;
}

int dequeue(queue_t* queue)
{
    int dequeued;
    queueNode_t* dequeuedNode;

    if (isEmpty(queue))
        return 0;

    dequeuedNode = queue->head;
    dequeued = queue->head->element;
    queue->head = queue->head->next;

    free(dequeuedNode);
    return dequeued;
}

int first(queue_t* queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->head->element; 
}

void printQueue(queue_t* queue)
{
    queueNode_t* node = queue->head;

    while (node != NULL)
    {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("\n");
}

void destroyQueue(queue_t* queue)
{
    queueNode_t* node = queue->head;
    queueNode_t* nextNode;

    while (node != NULL) 
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }

    queue->head = NULL;
}