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
    /**
     * Hash set method, inserting each node index until we find a duplicate
     */
    // bool hasCycle(ListNode* head) {
    //     std::unordered_set<ListNode*> visited;

    //     while (head) {
    //         if (visited.find(head) != visited.end()) {
    //             return true;
    //         } 

    //         visited.insert(head);
    //         head = head->next;
    //     }

    //     return false;
    // }

    /**
     * Slow & Fast pointer, checking if the slow and the fast pointer meet meaning a cycle has been detected
     */
    bool hasCycle(ListNode* head) {
        ListNode* fast{head};
        ListNode* slow{head};

        while (fast && fast->next) { 
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
