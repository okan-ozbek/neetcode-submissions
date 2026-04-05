// Singly Linked List Node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val, ListNode* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};
  
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        int iteration{0};
        auto* node{head};

        while (node != nullptr) {
            if (iteration == index) {
                return node->val;
            }

            ++iteration;
            node = node->next;
        }
        
        return -1;
    }

    void insertHead(int val) {
        auto* node = new ListNode(val);

        node->next = head;
        head = node;

        if (node->next == nullptr) {
            tail = node;
        }
    }
    
    void insertTail(int val) {
        auto* node = new ListNode(val);

        if (tail == nullptr) {
            head = node;
            tail = node;
            return;
        }

        tail->next = node;
        tail = tail->next;
    }

    bool remove(int index) {
        int iteration{0};
        auto* node{head};

        if (index == 0 && head != nullptr) {
            auto* deletable = head;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            delete deletable;
            return true;
        }

        while (iteration + 1 < index && node != nullptr) {
            ++iteration;
            node = node->next;
        }

        if (node != nullptr && node->next != nullptr) {
            if (node->next == tail) {
                tail = node;
            }

            auto* deletable = node->next;
            node->next = node->next->next;

            delete deletable;
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> result{};
        auto* node{head};

        while (node != nullptr) {
            result.push_back(node->val);
            node = node->next;
        }

        return result;
    }
};
