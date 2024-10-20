#ifndef DYN_STACK
#define DYN_STACK
#include <stdio.h>
#include <stdlib.h>
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

typedef struct stackNode 
{
    int element;
    struct stackNode* next;     // 'Next' here is going downwards in the stack
} stackNode_t;

typedef struct dynamicStack 
{
    stackNode_t* top;
} dynamicStack_t;

// Creates a node of the stack
stackNode_t* createNode(int element);

// Creates the stack
void initializeStack(dynamicStack_t* stack);

// Checks if the stack is empty, returns 1 if so and 0 otherwise.
int isEmpty(dynamicStack_t* stack);

// Pushes a new element to the stack, returns 1 if succeeded and 0 if failed.
int push(dynamicStack_t* stack, int element);

// Pops element from the top, returns it if succeeded and 0 if failed.
int pop(dynamicStack_t* stack);

// Gets the element from the top, returns it if succeeded and NULL if failed.
int peek(dynamicStack_t* stack);

// Print the stack from bottom to the top
void printStack(dynamicStack_t* stack);

// Destroys stack and frees memory
void destroyStack(dynamicStack_t* stack);

#endif