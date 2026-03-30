/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    /***
      * Logic: We need to reverse the Linked List, so what we do is we basically swap the direction of the Linked List
      * Instead of pointing to the right we start iterating over it to make it point to the left
      *
      * Example: head = 0 -> 1 -> 2 -> 3 
      * Reverse:        0 <- 1 <- 2 <- 3 = prev 
      *
      * Previous starts at the end pointing back
      * Another way of viewing it is as follows:
      * prev = 3 -> 2 -> 1 -> 0
    ***/
    ListNode* reverseList(ListNode* head) {
        ListNode* currentNode{head};
        ListNode* previousNode{nullptr};

        while(currentNode != nullptr) {
            ListNode* nextNode{currentNode->next};

            currentNode->next = previousNode;
            previousNode = currentNode;

            currentNode = nextNode;
        }

        return previousNode;
    }
};
