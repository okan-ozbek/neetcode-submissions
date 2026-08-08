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
    void reorderList(ListNode* head) {
        auto* slow = head;
        auto* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto* second = slow->next;
        auto* previous = slow->next = nullptr;

        while (second != nullptr) {
            auto* temp = second->next; 

            second->next = previous; // 4
            previous = second; // 5
            second = temp; // 6
        }

        auto* first = head;
        second = previous;

        while (second != nullptr) {
            auto* first_temp = first->next;
            auto* second_temp = second->next;

            first->next = second;
            second->next = first_temp;
            first = first_temp;
            second = second_temp;
        }
    }
};
