#include <stdio.h>
#include "dynamicStack.h"

int main()
{
    dynamicStack_t stack;
    initializeStack(&stack);

    // Pushing 3 elements into the stack
    push(&stack, 7);
    push(&stack, 200);
    push(&stack, 2);

    printf("Top element is %d\n", peek(&stack));

    // Popping 2 elements from the stack
    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));

    printf("Top element is %d\n", peek(&stack));

    pop(&stack);

    // Trying to pop an element with empty stack
    pop(&stack);

    destroyStack(&stack);

    return 0;
}