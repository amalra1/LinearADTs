#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedList.h"

int main() 
{
    linkedList_t list;
    initializeList(&list);

    // Seed the random number generator
    srand(time(NULL));

    // Test: Add random elements to head and tail
    for (int i = 0; i < 10; i++) {
        int randNum = rand() % 100;
        if (i % 2 == 0) {
            addHead(&list, randNum);
        } else {
            addTail(&list, randNum);
        }
    }
    printf("List after adding random elements to head and tail: ");
    printList(&list);

    // Test: Add elements at random indices
    for (int i = 0; i < 5; i++) {
        int randNum = rand() % 100;
        int randIndex = rand() % (size(&list) + 1);
        addIndex(&list, randNum, randIndex);
    }
    printf("List after adding random elements at random indices: ");
    printList(&list);

    // Test: Remove elements from head and tail
    for (int i = 0; i < 3; i++) {
        printf("Removed head: %d\n", removeHead(&list));
        printf("Removed tail: %d\n", removeTail(&list));
        printList(&list);
    }

    // Test: Peek at head and tail elements
    printf("Current head: %d\n", head(&list));
    printf("Current tail: %d\n", tail(&list));

    // Test: List size
    printf("Current size: %d\n", size(&list));

    // Test: Destroy list
    destroyList(&list);
    printf("List after destruction: ");
    printList(&list);  // Should be empty

    return 0;
}
