#include <stdio.h>
#include "queue.h"

int main() 
{
    queue_t queue;
    initializeQueue(&queue);

    // Test: Enqueue elements
    printf("Enqueueing elements: 155, 22, 79\n");
    enqueue(&queue, 155);
    enqueue(&queue, 22);
    enqueue(&queue, 79);
    printQueue(&queue);

    // Test: Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&queue));
    printQueue(&queue);

    // Test: Peek at first element
    printf("First element: %d\n", first(&queue));
    printQueue(&queue);

    // Test: Dequeue all elements
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printQueue(&queue);

    // Test: Try to dequeue from empty queue
    printf("Dequeued element: %d\n", dequeue(&queue));  // Should indicate failure or underflow
    printQueue(&queue);

    // Test: Enqueue and Dequeue mixed
    enqueue(&queue, 90);
    enqueue(&queue, 1);
    printf("First element: %d\n", first(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    enqueue(&queue, 1700);
    printQueue(&queue);

    // Test: Destroy queue
    destroyQueue(&queue);
    printf("Queue after destruction:\n");
    printQueue(&queue);  // Should be empty

    return 0;
}
