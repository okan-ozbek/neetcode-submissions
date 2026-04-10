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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* dummy = new ListNode(0, head);
        auto* left{dummy};
        auto* right{head};

        while (n > 0 && right != nullptr) {
            right = right->next;
            n -= 1;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;


        // // auto* l = head;
        // // auto* r = head;

        // // int curr_dist{0};
        // // int dist{n + 1};

        // // while (curr_dist < dist && r != nullptr) {
        // //     ++curr_dist;
        // //     r = r->next;
        // // }

        // // while (r != nullptr) {
        // //     l = l->next;
        // //     r = r->next;
        // // }

        // l->next = l->next->next;

        // return head;
    }
};
