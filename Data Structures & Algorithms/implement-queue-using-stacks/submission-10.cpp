class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x);
    }

    int pop() {
        std::size_t fn{ first.size() };
        for (std::size_t i{}; i < fn; ++i) {
            second.push(first.top());
            first.pop();
        }

        int v = second.top();
        second.pop();

        std::size_t sn{ second.size() };
        for (std::size_t i{}; i < sn; ++i) {
            first.push(second.top());
            second.pop();
        }

        return v;
    }

    int peek() {
        int val{};
        std::size_t fn{ first.size() };
        for (std::size_t i{}; i < fn; ++i) {
            val = first.top();
            second.push(first.top());
            first.pop();
        }

        std::size_t sn{ second.size() };
        for (std::size_t i{}; i < sn; ++i) {
            first.push(second.top());
            second.pop();
        }

        return val;
    }
    
    bool empty() {
        return first.empty() && second.empty();
    }

private:
    std::stack<int> first{};
    std::stack<int> second{};
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */