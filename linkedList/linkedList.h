#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdio.h>
#include <stdlib.h>
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

typedef struct node
{
    int element;
    struct node* next;
} node_t;

typedef struct linkedList
{
    node_t* head;
    node_t* tail;
    int size;
} linkedList_t;

// Creates a node of the list
node_t* createNode(int element);

// Creates the list
void initializeList(linkedList_t* list);

// Checks if the list is empty, returns 1 if so and 0 otherwise.
int isEmpty(linkedList_t* list);

// Returns the size of the list so far
int size(linkedList_t* list);

// Adds a new element to the head of the list, returns 1 if succeeded and 0 if failed.
int addHead(linkedList_t* list, int element);

// Adds a new element to the tail of the list, returns 1 if succeeded and 0 if failed.
int addTail(linkedList_t* list, int element);

// Adds a new element to a given index of the list, returns 1 if succeeded and 0 if failed.
int addIndex(linkedList_t* list, int element, int index);

// Removes the element from the head of the list, returns it if succeeded and 0 if failed.
int removeHead(linkedList_t* list);

// Removes the element from the tail of the list, returns it if succeeded and 0 if failed.
int removeTail(linkedList_t* list);

// Gets the first element from the list, returns it if succeeded and 0 if failed.
int head(linkedList_t* list);

// Gets the last element from the list, returns it if succeeded and 0 if failed.
int tail(linkedList_t* list);

// Prints the list
void printList(linkedList_t* list);

// Destroys list and frees memory
void destroyList(linkedList_t* list);

#endif