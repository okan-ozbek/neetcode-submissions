class MyStack {
public:
    MyStack() = default;
    
    void push(int x) {
        q.push(x);

        /**
         * Limitation: We need to use a traditional queue (FIFO)
         *             and transform it into a stack (FILO)
         *
         * Idea: When we push a new item, we shuffle the deck so it's
         *       all the way in the front, basically making a shit optimized
         *       version of a stack.
         * 
         * Example: Imagine [1, 2, 3] and we want to push 4
         *          currently 1 is in line to get popped but since
         *          we want to push 4, it should be 4. This is what 
         *          the loop below does:
         *
         *          1. [1, 2, 3, ..4..] We insert 4 at the back.
         *          2. [2, 3, ..4.., 1] Then we pop 1, and reinsert it at the back.
         *          3. [3, ..4.., 1, 2] Same for 2.
         *          4. [..4.., 1, 2, 3] Same for 3, viola, 4 is at the front.
         */
        for (int i{}; i < q.size() - 1; ++i) {
            int p{ q.front() };

            q.pop();
            q.push(p);
        }
    }
    
    int pop() {
        int t{ q.front() }; q.pop();

        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q{};
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */