class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
    
    Node(int value, Node* next) : value(value), next(next), prev(nullptr) {}

    Node(int value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}
};

class Deque {
public:
    Node* head;
    Node* tail;

    Deque() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return (head == nullptr && tail == nullptr);
    }

    void append(int value) {
        if (tail == nullptr) {
            head = new Node(value);
            tail = head;
            return;
        }

        auto* old{tail};
        auto* cur = new Node(value);

        old->next = cur;
        cur->prev = old;

        tail = cur;
    }

    void appendleft(int value) {
        if (head == nullptr) {
            head = new Node(value);
            tail = head;
            return;
        }

        auto* old{head};
        auto* cur = new Node(value);

        old->prev = cur;
        cur->next = old;
        head = cur;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        auto* deletable{tail};
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = deletable->prev;
            tail->next = nullptr;
        }

        auto value{deletable->value};

        delete deletable;

        return value;
    }

    int popleft() {
        if (isEmpty()) {
            return -1;
        }

        auto* deletable{head};

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = deletable->next;
            head->prev = nullptr;
        }

        auto value{deletable->value};

        delete deletable;
        return value;
    }
};
