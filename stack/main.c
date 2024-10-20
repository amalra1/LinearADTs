#include <stdio.h>
#include "stack.h"

#define CAPACITY 100

int main()
{
    stack_t* stack = initializeStack(CAPACITY);

    // Expected to be: -1
    printf("%d\n", peek(stack));

    // Pushing '10' to the stack
    push(stack, 10);

    // Expected to be: 0
    printf("%d\n", peek(stack));
    printStack(stack);

    pop(stack);

    // Expected to be: -1
    printf("%d\n", peek(stack));

    // Expected: Nothing to happen
    pop(stack);

    for (int i = 0; i < CAPACITY; i++)
        push(stack, i);

    // Expected: 100 numbers added to the stack
    printf("%d\n", peek(stack));
    printStack(stack);

    // Expected: Nothing to happen
    push(stack, 999);

    printf("%d\n", peek(stack));
    printStack(stack);

    destroyStack(stack);

    return 0;
}