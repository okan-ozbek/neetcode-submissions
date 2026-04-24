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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* dummy{ new ListNode() };
        auto* current{ dummy };
        
        int carry{ 0 };

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int value_1{ (l1 != nullptr) ? l1->val : 0 };
            int value_2{ (l2 != nullptr) ? l2->val : 0 };
            int sum{ value_1 + value_2 + carry };
            
            carry = sum / 10;
            sum = sum % 10;

            current->next = new ListNode(sum);
            current = current->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummy->next;

        delete dummy;

        return result;
    }
};
