#include <stdio.h>
#include <stdlib.h>

// Node struct
typedef struct Node {
  char value;
  struct Node *next;

} Node;

// Create a circular LL
Node *createCircularLL() {
  int numberOfElements = 0;
  char inputValue;
  printf("Enter the number of elements:");
  scanf("%d", &numberOfElements);

  Node *headptr;
  Node *previousNodePtr=NULL;


  for (int index = 0; index < numberOfElements; index++) {
    printf("enter letter:");

    if (getchar() != 0) {
      inputValue = getchar();
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = inputValue;
    newNode->next = NULL;
    if(previousNodePtr!=NULL){
        previousNodePtr->next=newNode;
        previousNodePtr=newNode;
    }



    if (index == 0) {
      headptr = newNode;
      previousNodePtr=headptr;

    } else if (index == numberOfElements - 1) {
      newNode->next = headptr;
    }
  }

  return headptr;
}

// traversing a circular LL
int traverseCircularLL(Node *headptr) {
  int count = 0, alreadyTraversedHeadPtr = 0;
  Node *node = headptr;

  while (node != headptr || !alreadyTraversedHeadPtr) {
    printf("%c", node->value);
    node = node->next;

    if(node==headptr){
        alreadyTraversedHeadPtr=1;
    }
    count++;
  }

  printf("\n");
  return count;
}


//inserting at the beginning in a circular LL
Node* insertAtBeginningOfCircularLL(Node* headptr, char valueToInsert){
  Node* newNodePtr=(Node*) malloc(sizeof(Node));
  newNodePtr->value=valueToInsert;
  newNodePtr->next=headptr;

  Node* node=headptr;
  while(node->next!=headptr){
    node=node->next;
  }

  node->next=newNodePtr;


  return newNodePtr;
}

//insert at the end of the circular LL
void insertAtEndOfCircularLL(Node* headptr, char valueToInsert){
  Node* newNodePtr=(Node*)malloc(sizeof(Node));
  newNodePtr->value=valueToInsert;

  Node* node=headptr;

  
  while(node->next!=headptr){
    node=node->next;
  }

  node->next=newNodePtr;
  newNodePtr->next=headptr;

}

//insert after a particular position
void insertAtAParticularPosition(Node* headptr, char valueToInsert, char insertAfter){
  Node* newNodePtr= (Node*) malloc(sizeof(Node));
  newNodePtr->value=valueToInsert;
  newNodePtr->next=NULL;

  Node* node=headptr;
  while(node->next!=headptr && node->value!=insertAfter){
    node=node->next;
  }

  if(node->next==headptr){
    printf("The value after which the current element is to be inserted is not present\n");
    free(newNodePtr);
    return;
  }

  newNodePtr->next= node->next;
  node->next=newNodePtr;

}


//insert in a sorted circular LL
void insertInSortedLL(Node* headptr, char valueToInsert){
  
  Node* node=headptr;
  Node* ptr2= headptr->next;
  while(ptr2!=headptr && ptr2->value <= valueToInsert ){
    node=node->next;
    ptr2=ptr2->next;
  }

  Node* newNodePtr= (Node*) malloc(sizeof(Node));
  newNodePtr->value=valueToInsert;

  if(ptr2==headptr){
   newNodePtr->next=headptr;
   node->next=newNodePtr;
   return;
  }

  node->next= newNodePtr;
  newNodePtr->next=ptr2;

}


//Delete from beginning
Node* deleteFromBeginningOfCircularLL(Node* headptr){
  Node* node=headptr;
  while(node->next!=headptr){
    node=node->next;
  }
  node->next= headptr->next;
  node=headptr->next;
  free(headptr);
  return node;
  
}

//delete from end

void deleteFromEndOfCircularLL(Node* headptr){
  Node* node=headptr;
  Node* ptr2= headptr->next;
  while(ptr2->next!=headptr){
    node=node->next;
    ptr2=ptr2->next;
  }

  node->next=headptr;
  free(ptr2);

}


//delete a particular element

void deleteAParticularElement(Node* headptr, char elementToDelete){
  Node* ptr1= headptr;
  Node* ptr2=headptr->next;

  while(ptr2->next!=headptr && ptr2->value!=elementToDelete){
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }

  if(ptr2->next==headptr){
    printf("The element to delete is not present in the list\n");
    return;
  }

  ptr1->next=ptr2->next;
  free(ptr2);

}




/////////////////////////////////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////////////////////////
int main() {

  Node *ll1 = createCircularLL();
  int count=traverseCircularLL(ll1);

  

  Node* newHeadOfLL1= insertAtBeginningOfCircularLL(ll1, 'a');
  traverseCircularLL(newHeadOfLL1);

  insertAtEndOfCircularLL(newHeadOfLL1, 'z');
  traverseCircularLL(newHeadOfLL1);

  insertAtAParticularPosition(newHeadOfLL1, 'm', 'd');
  traverseCircularLL(newHeadOfLL1);

  insertInSortedLL(newHeadOfLL1, 'e');
  traverseCircularLL(newHeadOfLL1);


  ll1=deleteFromBeginningOfCircularLL(ll1);
  traverseCircularLL(ll1);
  
  deleteFromEndOfCircularLL(ll1);
  traverseCircularLL(ll1);
  
  deleteAParticularElement(ll1, 'e');
  traverseCircularLL(ll1);

  getchar();
}