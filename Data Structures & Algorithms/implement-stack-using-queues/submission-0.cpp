class MyStack {
public:
    MyStack() = default;
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int temp{ q.back() };
        q.pop_back();

        return temp;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    std::deque<int> q{};
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */