#ifndef STACK
#define STACK
#include <stdio.h>
#include <stdlib.h>
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

typedef struct stack
{
    int maxSize;
    int top;
    int* elements;
} stack_t;

// Creates the stack given a maxSize
stack_t* initializeStack(int maxSize);

// Checks if the stack is full, returns 1 if so and 0 otherwise.
int isFull(stack_t* stack);

// Checks if the stack is empty, returns 1 if so and 0 otherwise.
int isEmpty(stack_t* stack);

// Pushes a new element to the stack, returns 1 if succeeded and 0 if failed.
int push(stack_t* stack, int element);

// Pops element from the top, returns it if succeeded and 0 if failed.
int pop(stack_t* stack);

// Gets the element from the top, returns it if succeeded and 0 if failed.
int peek(stack_t* stack);

// Print the stack from 0 to top
void printStack(stack_t* stack);

void destroyStack(stack_t* stack);

#endif