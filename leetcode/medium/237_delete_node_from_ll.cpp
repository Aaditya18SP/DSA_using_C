/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <cstddef>
 #include <iostream>
 #include <stdlib.h>

struct ListNode {
    int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
  }; 

class Solution {
public:
    void deleteNode(ListNode* node) {
       // std::cout<<"next node value is:" << nextNodeValue<<std::endl;
        ListNode* nextNode= node->next;
        int nextNodeValue= nextNode->val;

        node->val= nextNodeValue;
        //std::cout << nextNodeValue<<std::endl;
        node->next=nextNode->next;
        
    }

    ListNode* traverseLL(ListNode* headNode, int returnAddressOfThisNode){
        ListNode* nodeToReturn=NULL;
        while(headNode!=NULL){

            if(headNode->val==returnAddressOfThisNode){
                nodeToReturn=headNode;

            }
            std::cout<<headNode->val<<" ";
            headNode=headNode->next;
        }

        std::cout<<std::endl;
        return nodeToReturn;
    }

    ListNode* createLL(){
        ListNode* previousNode,* headNode;
        for(int i=0; i<4; i++){
            int value;
            ListNode* node= (ListNode*) malloc(sizeof(ListNode));
            std::cout<<"enter value of node:";
            std::cin>>value;
            node->val= value;

            if(previousNode!=NULL){
                previousNode->next= node;
                previousNode=node;
            }

            if(i==0){
                previousNode=node;
                headNode=node;
            }
        }


        return headNode;
    }
};


int main(){
    Solution s= Solution();
    ListNode* headNode=s.createLL();
    ListNode* nodeToDelete=s.traverseLL(headNode,5);
    s.deleteNode(nodeToDelete);
    s.traverseLL(headNode,0);
    
}