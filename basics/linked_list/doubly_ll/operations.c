#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char value;
  struct Node *next;
  struct Node *prev;

} Node;

// 1. create a doubly linked list
Node **createDoublyLL() {
  int noOfElements;
  printf("Enter the number of elements you want in the LL:");
  scanf("%d", &noOfElements);
  char inputValue;
  Node *previousNodePtr = NULL;
  Node *headPtr = NULL;
  Node *tailPtr = NULL;
  Node **ptrArray = (Node **)malloc(2 * sizeof(Node *));

  for (int index = 0; index < noOfElements; index++) {
    printf("enter value:");

    if (getchar() != 0) {
      inputValue = getchar();

      Node *newNodePtr = (Node *)malloc(sizeof(Node));
      newNodePtr->value = inputValue;
      newNodePtr->next = NULL;

      if (previousNodePtr != NULL) {
        newNodePtr->prev = previousNodePtr;
        previousNodePtr->next = newNodePtr;
        previousNodePtr = newNodePtr;
      }

      if (index == 0) {
        newNodePtr->prev = NULL;
        previousNodePtr = newNodePtr;
        headPtr = newNodePtr;
      } else if (index == noOfElements - 1) {
        newNodePtr->next = NULL;
        tailPtr = newNodePtr;
      }
    }
  }

  ptrArray[0] = headPtr;
  ptrArray[1] = tailPtr;
  return ptrArray;
}

// 2. traverse LL
int traverseDoublyLL(Node **ptrArray) {
  Node *headPtr = ptrArray[0];
  Node *tailPtr = ptrArray[1];

  Node *node = headPtr;
  Node *node2 = tailPtr;

  int index = 0, count = 0, initialSizeOfString = 10;
  char *fromHead = (char *)malloc(initialSizeOfString * sizeof(char)),
       *fromTail = (char *)malloc(initialSizeOfString * sizeof(char));

  while (node != NULL && node2 != NULL) {

    if (index > initialSizeOfString) {
      fromHead = (char *)realloc(fromHead, initialSizeOfString + 10);
      fromTail = (char *)realloc(fromTail, initialSizeOfString + 10);
      initialSizeOfString += 10;
    }

    fromHead[index] = node->value;
    fromHead[index + 1] = ' ';

    fromTail[index] = node2->value;
    fromTail[index + 1] = ' ';

    node = node->next;
    node2 = node2->prev;

    index += 2;
    count++;
  }

  printf("\nFrom the head side: %s\nAnd from the tail side: %s\n", fromHead,
         fromTail);

  return count;
}

// insert at beginning into a doubly linked list
Node *insertAtBeginningOfDLL(Node *headPtr, char valueToInsert) {
  Node *newNodePtr = (Node *)malloc(sizeof(Node));
  newNodePtr->value = valueToInsert;
  newNodePtr->prev = NULL;

  newNodePtr->next = headPtr;
  headPtr->prev = newNodePtr;

  return newNodePtr;
}

// insert at the end of the Two-way linked list
Node *insertAtTheEndOfDLL(Node *endPtr, char valueToInsert) {
  Node *newNodePtr = (Node *)malloc(sizeof(Node));
  newNodePtr->value = valueToInsert;
  newNodePtr->next = NULL;
  newNodePtr->prev = endPtr;
  endPtr->next = newNodePtr;
  return newNodePtr;
}

void insertAfterAParticularElement(Node *headPtr, char valueToInsert,
                                   char insertAfter) {

  while (headPtr != NULL && headPtr->value != insertAfter) {
    headPtr = headPtr->next;
  }

  if (headPtr == NULL) {
    printf("Couldn't locate the element after which the new element needs to "
           "be inserted\n");
    return;
  }

  Node *newNodePtr = (Node *)malloc(sizeof(Node));
  newNodePtr->value = valueToInsert;
  newNodePtr->prev = headPtr;
  newNodePtr->next = headPtr->next;

  headPtr->next->prev = newNodePtr;
  headPtr->next = newNodePtr;
}

Node **insertIntoASortedDLL(Node *headPtr, Node *endPtr, char valueToInsert) {
  // assumption that list is sorted in the ascending order
  Node **ptrArray = (Node **)malloc(2 * sizeof(Node *));

  if (valueToInsert < headPtr->value) {
    headPtr = insertAtBeginningOfDLL(headPtr, valueToInsert);
    ptrArray[0] = headPtr;
    ptrArray[1] = endPtr;
    return ptrArray;
  } else if (valueToInsert > endPtr->value) {
    endPtr = insertAtTheEndOfDLL(endPtr, valueToInsert);
    ptrArray[0] = headPtr;
    ptrArray[1] = endPtr;
    return ptrArray;
  }

  Node *node1 = headPtr;
  Node *node2 = headPtr->next;

  while (node2 != NULL && node2->value < valueToInsert) {
    node1 = node1->next;
    node2 = node2->next;
  }

  if (node2 == NULL) {
    endPtr = insertAtTheEndOfDLL(endPtr, valueToInsert);

  } else {
    Node *newNodePtr = (Node *)malloc(sizeof(Node));
    newNodePtr->value = valueToInsert;
    newNodePtr->next = node2;
    newNodePtr->prev = node1;
    node1->next = newNodePtr;
    node2->prev = newNodePtr;
  }

  ptrArray[0] = headPtr;
  ptrArray[1] = endPtr;

  return ptrArray;
}

//////////////////////////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
  Node **ptrArray = createDoublyLL();

  traverseDoublyLL(ptrArray);

  ptrArray[0] = insertAtBeginningOfDLL(ptrArray[0], 'A');
  traverseDoublyLL(ptrArray);
  ptrArray[1] = insertAtTheEndOfDLL(ptrArray[1], 'y');
  traverseDoublyLL(ptrArray);

  insertAfterAParticularElement(ptrArray[0], 'm', 'd');
  traverseDoublyLL(ptrArray);

  ptrArray = insertIntoASortedDLL(ptrArray[0], ptrArray[1], 'z');
  traverseDoublyLL(ptrArray);
  getchar();
}
