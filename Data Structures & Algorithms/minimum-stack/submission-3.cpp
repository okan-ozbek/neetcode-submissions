class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
        reg.push(val);
        min.push(this->getMinValue(val));
    }
    
    void pop() {
        reg.pop();
        min.pop();
    }
    
    int top() {
        return reg.top();
    }
    
    int getMin() {
        return min.top();
    }

private:
    std::stack<int> reg{};
    std::stack<int> min{};

    int getMinValue(int val) {
        if (min.empty() == false) { 
            return (val < min.top()) 
                ? val
                : min.top();
        }

        return val;
    }
};
