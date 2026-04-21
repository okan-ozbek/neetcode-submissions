class MyStack {
public:
    MyStack() = default;
    
    void push(int x) {
        q.push(x);

        for (int i{}; i < q.size() - 1; ++i) {
            int p{ q.front() };

            q.pop();
            q.push(p);
        }
    }
    
    int pop() {
        int t{ q.front() };

        q.pop();

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