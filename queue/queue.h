#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <stdlib.h>
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

typedef struct queueNode 
{
    int element;
    struct queueNode* next;    
} queueNode_t;

typedef struct queue 
{
    queueNode_t* head;
    queueNode_t* tail;
} queue_t;

// Creates a node of the queue
queueNode_t* createNode(int element);

// Creates the queue
void initializeQueue(queue_t* queue);

// Checks if the queue is empty, returns 1 if so and 0 otherwise.
int isEmpty(queue_t* queue);

// Adds a new element to the end of the queue, returns 1 if succeeded and 0 if failed.
int enqueue(queue_t* queue, int element);

// Removes the first element from the queue, returns it if succeeded and 0 if failed.
int dequeue(queue_t* queue);

// Gets the first element from the queue, returns it if succeeded and 0 if failed.
int first(queue_t* queue);

// Print the queue 
void printQueue(queue_t* queue);

// Destroys queue and frees memory
void destroyQueue(queue_t* queue);

#endif