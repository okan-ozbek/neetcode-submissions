class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);

        if (ms.empty()) {
            ms.push_back(val);
            return;
        } 

        int minVal = (val < ms[ms.size() - 1]) 
            ? val
            : ms[ms.size() - 1];

        ms.push_back(minVal);
    }
    
    void pop() {
        s.pop_back();
        ms.pop_back();
    }
    
    int top() {
        return s[s.size() - 1];
    }
    
    int getMin() {
        return ms[ms.size() - 1];
    }

private:
    std::vector<int> s{};
    std::vector<int> ms{};
};
