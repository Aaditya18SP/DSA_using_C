#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *createLL() {
  struct Node *headPtr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *node = headPtr;
  struct Node *previousNode = node;

  int noOfElements, i = 0, value;
  printf("Enter the number of elements in the LL:");
  scanf("%d", &noOfElements);
  while (i < noOfElements) {

    if (node == NULL) {
      node = (struct Node *)malloc(sizeof(struct Node));
      node->next = NULL;
      previousNode->next = node;
    }

    printf("enter a value: ");
    scanf("%d", &value);
    node->value = value;
    i++;
    previousNode = node;
    node = node->next;
    // previousNode=node;
  }

  return headPtr;
}

int traverseLL(struct Node *headPtr) {
  struct Node *node = headPtr;
  int count = 0;

  while (node != NULL) {
    printf("%d ", node->value);
    count++;
    node = node->next;
  }

  printf("\n");

  return count;
}

void searchLL(struct Node *headPtr, int elementToLookFor) {
  struct Node *node = headPtr;
  while (node != NULL) {
    if (node->value == elementToLookFor) {
      printf("The value is found at address %p\n", node);
      break;
    }
    node = node->next;
  }
}

struct Node *insertAtBeginningOfLL(struct Node *headPtr, int valueToInsert) {
  struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
  newNodePtr->value = valueToInsert;
  newNodePtr->next = headPtr;
  headPtr = newNodePtr;
  return headPtr;
}

void insertAtEndOfLL(struct Node *headPtr, int valueToInsert) {
  struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
  newNodePtr->value = valueToInsert;

  struct Node *node = headPtr;
  while (node->next != NULL) {
    node = node->next;
  }

  node->next = newNodePtr;
}

void insertAtParticularPosition(struct Node *headPtr, int valueToInsert,
                                int insertAfterThisValue) {
  struct Node *ptr1 = headPtr;

  // int isElementToInsertAfterFound=0;

  while (ptr1 != NULL && ptr1->value != insertAfterThisValue) {
    ptr1 = ptr1->next;
  }
  struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
  newNodePtr->value = valueToInsert;
  newNodePtr->next = ptr1->next;
  ptr1->next = newNodePtr;
  printf("inserted successfully\n");
}

void insertInASortedLL(struct Node *headPtr, int valueToInsert,
                       int listIsSortedIn) {
  // 0-> list is sorted in ascending order
  // any other number -> list is sorted in descending order

  struct Node *ptr1 = headPtr;
  struct Node *ptr2 = ptr1->next;

  struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
  newNodePtr->value = valueToInsert;

  if (headPtr == NULL) {
    headPtr = newNodePtr;
    return;
  }

  if (listIsSortedIn == 0) {

    // check whether the element needs to be inserted at the beginning of the
    // list
    if (valueToInsert < headPtr->value) {
      newNodePtr->next = headPtr->next;
      headPtr = newNodePtr;
      return;
    }

    while (ptr2 != NULL && valueToInsert > ptr2->value) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }

    newNodePtr->next = ptr2;
    ptr1->next = newNodePtr;
  } else {

    if (valueToInsert > headPtr->value) {
      newNodePtr->next = headPtr->next;
      headPtr = newNodePtr;
    }

    // descending order
    ptr1 = headPtr;
    ptr2 = ptr1->next;
    // nextNode=node->next;
    // struct Node* previousNode=headPtr;

    while (ptr2 != NULL && ptr2->value > valueToInsert) {

      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }

    newNodePtr->next = ptr2;
    ptr1->next = newNodePtr;
  }
}

struct Node *deleteFromBeginning(struct Node *headPtr) {
  struct Node *newHead = headPtr->next;
  free(headPtr);
  return newHead;
}

void deleteFromEnd(struct Node *headPtr) {

  struct Node *node = headPtr;
  // struct Node*
  while (node->next->next != NULL) {
    node = node->next;
  }

  free(node->next);
  node->next = NULL;
}

void deleteAParticularNode(struct Node *headPtr, int valueToDelete) {
  struct Node *node = headPtr;
  struct Node *previousNode = node;
  while (node != NULL) {
    if (node->value == valueToDelete) {
      previousNode->next = node->next;
      free(node);
      break;
    }

    previousNode = node;
    node = node->next;
  }
}

struct Node *copyLL(struct Node *headPtr) {
  struct Node *node = headPtr;
  struct Node *copiedLLHeadPtr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *copiedLLNode = copiedLLHeadPtr;
  struct Node *copiedLLPreviousNode = copiedLLNode;
  struct Node *newNodePtr = NULL;
  while (node != NULL) {

    if (copiedLLNode == NULL) {
      newNodePtr = (struct Node *)malloc(sizeof(struct Node));
      newNodePtr->next = NULL;
      copiedLLNode = newNodePtr;
    }
    copiedLLNode->value = node->value;

    if (copiedLLPreviousNode != copiedLLNode) {
      copiedLLPreviousNode->next = copiedLLNode;
    }

    copiedLLPreviousNode = copiedLLNode;
    copiedLLNode = copiedLLNode->next;
    node = node->next;
  }

  return copiedLLHeadPtr;
}

struct Node *mergeSortedLL(struct Node *headPtr1, struct Node *headPtr2) {

  // sorting in ascending order

  struct Node *mergedLLHeadPtr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *mergedLLPreviousPtr = mergedLLHeadPtr;
  struct Node *mergedLLNode = mergedLLHeadPtr;

  while (headPtr1 != NULL && headPtr2 != NULL) {

    if (mergedLLNode == NULL) {
      struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
      newNodePtr->next = NULL;
      mergedLLNode = newNodePtr;
    }

    if (headPtr1->value <= headPtr2->value) {
      mergedLLNode->value = headPtr1->value;
      headPtr1 = headPtr1->next;

    } else {
      mergedLLNode->value = headPtr2->value;
      headPtr2 = headPtr2->next;
    }

    if (mergedLLPreviousPtr != mergedLLNode) {
      mergedLLPreviousPtr->next = mergedLLNode;
      mergedLLPreviousPtr = mergedLLNode;
    }
    mergedLLNode = mergedLLNode->next;
  }

  if (headPtr1 == NULL) {
    while (headPtr2 != NULL) {
      if (mergedLLNode == NULL) {
        struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
        newNodePtr->next = NULL;
        mergedLLNode = newNodePtr;
      }

      mergedLLNode->value = headPtr2->value;
      if (mergedLLPreviousPtr != mergedLLNode) {
        mergedLLPreviousPtr->next = mergedLLNode;
        mergedLLPreviousPtr = mergedLLNode;
      }

      mergedLLNode = mergedLLNode->next;
      headPtr2 = headPtr2->next;
    }

  } else if (headPtr2 == NULL) {
    while (headPtr1 != NULL) {
      if (mergedLLNode == NULL) {
        struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
        newNodePtr->next = NULL;
        mergedLLNode = newNodePtr;
      }

      mergedLLNode->value = headPtr1->value;
      if (mergedLLPreviousPtr != mergedLLNode) {
        mergedLLPreviousPtr->next = mergedLLNode;
        mergedLLPreviousPtr = mergedLLNode;
      }

      mergedLLNode = mergedLLNode->next;
      headPtr1 = headPtr1->next;
    }
  }

  return mergedLLHeadPtr;
}

struct Node **splitLLIntoTwo(struct Node *headPtr) {
  int count = traverseLL(headPtr);

  int middleElement = count / 2, index = 0;
  printf("count is:%d, middle element is: %d\n", count, middleElement);

  struct Node *node = headPtr;
  struct Node *splitLL1HeadPtr = headPtr;
  struct Node *splitLL2HeadPtr;
  struct Node **arrayPointer =
      (struct Node **)malloc(2 * sizeof(struct Node *));

  while (index < middleElement - 1) {
    // printf("index is :%d, value pointing at is:%d\n",index,node->value);
    index++;
    node = node->next;
  }

  splitLL2HeadPtr = node->next;
  node->next = NULL;

  arrayPointer[0] = splitLL1HeadPtr;
  arrayPointer[1] = splitLL2HeadPtr;
  /* *(arrayPointer+0)=headPtr;
   *(arrayPointer+1)=splitLL2HeadPtr;
   */
  return arrayPointer;
}

struct Node *reverseLL(struct Node *headPtr) {
  struct Node *ptr1 = headPtr;
  struct Node *ptr2 = ptr1->next;
  struct Node *ptr3 = ptr2;

  // only one node
  if (ptr2 == NULL) {
    return ptr1;
  }

  // only two nodes
  if (ptr2->next == NULL) {
    ptr1->next = NULL;
    ptr2->next = ptr1;
    return ptr2;
  }

//more than two nodes
  ptr1->next=NULL;

  while (ptr3 != NULL) {

    ptr3 = ptr3->next;
    ptr2->next = ptr1;
    ptr1 = ptr2;
    if (ptr3 != NULL) {
      ptr2 = ptr3;
    }
  }

  return ptr2;
}

int main() {

  struct Node *begin = createLL();
  traverseLL(begin);

  /*
  struct Node* anotherLL= createLL();


  searchLL(begin, 3);
  begin= insertAtBeginningOfLL(begin,0);
  traverseLL(begin);

  insertAtEndOfLL(begin, 20);
  traverseLL(begin);

  insertAtParticularPosition(begin, 10, 5);
  traverseLL(begin);


  //insertInASortedLL(begin, 8, 1);
  //traverseLL(begin);


      begin=deleteFromBeginning(begin);
      traverseLL(begin);

      deleteFromEnd(begin);
      traverseLL(begin);

      deleteAParticularNode(begin, 3);
      traverseLL(begin);

      struct Node* copiedLL= copyLL(begin);
      traverseLL(copiedLL);

      struct Node* mergedArray= mergeSortedLL(begin,anotherLL);
      traverseLL(mergedArray);


      struct Node** arrayPointer=splitLLIntoTwo(mergedArray);

      traverseLL(arrayPointer[0]);
      traverseLL(arrayPointer[1]);

      */

  struct Node *reversedLL = reverseLL(begin);
  traverseLL(reversedLL);

  if (reversedLL != begin) {
    free(reversedLL);
  }
  free(begin);
  // free(copiedLL);
  // free(mergedArray);
  // free(arrayPointer);

  return 0;
}
