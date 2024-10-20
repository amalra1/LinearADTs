#include "stack.h"
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

stack_t* initializeStack(int maxSize)
{
    stack_t* stack = malloc(sizeof(stack));

    stack->maxSize = maxSize;
    stack->top = -1;
    stack->elements = malloc(sizeof(int) * maxSize);

    return stack;
}

int isFull(stack_t* stack)
{
    if (stack->top == stack->maxSize - 1)
        return 1;
    return 0;
}

int isEmpty(stack_t* stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

int push(stack_t* stack, int element)
{
    if (isFull(stack))
        return 0;
    
    stack->top++;
    stack->elements[stack->top] = element;
    return 1;
}

int pop(stack_t* stack)
{
    if (isEmpty(stack))
        return 0;
    
    int element = stack->elements[stack->top];
    stack->top--;
    return element;    
}

int peek(stack_t* stack)
{
    return stack->top;
}

void printStack(stack_t* stack)
{
    if (isEmpty(stack))
        printf("Empty Stack.\n");
    else
    {
        for(int i = 0; i <= stack->top; i++)
            printf("%d ", stack->elements[i]);
        printf("\n");
    }
}

void destroyStack(stack_t* stack)
{
    free(stack->elements);
    free(stack);
}