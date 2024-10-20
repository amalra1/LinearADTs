#include "dynamicStack.h"
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

stackNode_t* createNode(int element)
{
    stackNode_t* node = (stackNode_t*)malloc(sizeof(stackNode_t));

    node->element = element;
    node->next = NULL;

    return node;
}

void initializeStack(dynamicStack_t* stack)
{
    stack->top = NULL;
}

int isEmpty(dynamicStack_t* stack)
{
    if(stack->top == NULL)
        return 1;
    return 0;
}

int push(dynamicStack_t* stack, int element)
{
    stackNode_t* node = createNode(element);

    // In case malloc goes wrong
    if (!node)
        return 0;

    node->next = stack->top;
    stack->top = node;

    return 1;
}

int pop(dynamicStack_t* stack)
{
    stackNode_t* popped;
    int poppedElement;

    if (isEmpty(stack))
        return 0;
    
    popped = stack->top;
    stack->top = stack->top->next;

    poppedElement = popped->element;
    free(popped);

    return poppedElement;
}

int peek(dynamicStack_t* stack)
{
    return stack->top->element;
}

void printStack(dynamicStack_t* stack)
{
    // Prints reverse for now
    while (stack->top != NULL)
        printf("%d ", stack->top->element);
    printf("\n");
}

void destroyStack(dynamicStack_t* stack) 
{
    stackNode_t* current = stack->top;
    stackNode_t* nextNode;

    while (current != NULL) 
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    stack->top = NULL;
}