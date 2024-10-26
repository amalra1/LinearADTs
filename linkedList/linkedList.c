#include "linkedList.h"
/*
    MADE BY
    PEDRO AMARAL CHAPELIN
*/

node_t* createNode(int element)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->element = element;
    node->next = NULL;

    return node;
}

void initializeList(linkedList_t* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int isEmpty(linkedList_t* list)
{
    // Both head and tail pointers verification work here, size too
    if (list->head == NULL)
        return 1;
    return 0;
}       

int size(linkedList_t* list)
{
    return list->size;
}

int addHead(linkedList_t* list, int element)
{
    node_t* node = createNode(element);

    if (isEmpty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head; 
        list->head = node;
    }
    list->size++;
    return 1;
}

int addTail(linkedList_t* list, int element)
{
    node_t* node = createNode(element);

    if (isEmpty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node; 
        list->tail = node;
    }
    list->size++;
    return 1;
}

int addIndex(linkedList_t* list, int element, int index)
{
    node_t* node = createNode(element);
    node_t* currentNode = list->head;

    // Invalid index
    if (index < 0 || index > list->size - 1)
        return 0;

    // Empty list
    if (isEmpty(list) && index != 0)
        return 0;

    // Finds the spot
    for (int i = 0; i < index - 1; i++)
        currentNode = currentNode->next;
    
    // Deals with pointers
    node->next = currentNode->next;
    currentNode->next = node;

    // First position - Needs to update head pointer
    if (index == 0)
        list->head = node;

    // Last position- No need to update tail, because it adds and pushes the
    // tail to the right, can't add to last position using this function

    list->size++;
    return 1;
}

int removeHead(linkedList_t* list)
{
    int removed;
    node_t* removedNode;

    if (isEmpty(list))
        return 0;

    removedNode = list->head;
    removed = list->head->element;
    list->head = list->head->next;

    free(removedNode);

    list->size--;
    return removed;
}

int removeTail(linkedList_t* list)
{
    node_t* currentNode = list->head;
    int removedElement;

    if (isEmpty(list))
        return 0;
    
    while (currentNode->next->next != NULL)
        currentNode = currentNode->next;

    removedElement = currentNode->next->element;
    list->tail = currentNode;
    list->tail->next = NULL;

    currentNode = currentNode->next;

    free(currentNode);

    list->size--;
    return removedElement;
}

int head(linkedList_t* list)
{
    if (isEmpty(list))
        return 0;
    return list->head->element;
}

int tail(linkedList_t* list)
{
    if (isEmpty(list))
        return 0;
    return list->tail->element;
}

void printList(linkedList_t* list)
{
    node_t* node = list->head;

    while (node != NULL)
    {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("\n");
}


void destroyList(linkedList_t* list)
{
    node_t* node = list->head;
    node_t* nextNode;

    while (node != NULL) 
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }

    list->head = NULL;
    list->tail = NULL;
}
