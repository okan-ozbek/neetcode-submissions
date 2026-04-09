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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /**
         * If list1 is nullptr it means we reached the end, and we can't continue, return list2
         *
         * @return ListNode*
         */
        if (list1 == nullptr) {
            return list2;
        }

        /**
         * If list2 is nullptr it means we reached the end, and can't continue, return list1
         *
         * @return ListNode*
         */
        if (list2 == nullptr) {
            return list1;
        }

        /*
         * Check if list1->val is less or equal to list2->val
         *
         * a. If it is equal recurse through the function where we use list1->next as the list1 parameter
         *    the return value will be set to list1->next. Then return list1 back.
         * b. If it is equal recurse through the function where we use list2->next as the list2 parameter
         *    the return value will be set to list2->next. Then return list2 back.
         *
         * @return ListNode*
         */
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);

            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);

            return list2;
        }
    }
};
