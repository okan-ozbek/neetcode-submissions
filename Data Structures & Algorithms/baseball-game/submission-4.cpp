class Solution {
public:
    using StackRef = std::stack<int>&;
    using IntRef = int&;
    using ConstStringRef = const std::string&;

    [[nodiscard]] int calPoints(const vector<string>& operations) noexcept {
        std::stack<int> stck{}; 
        int result{};

        for (int i{}; i < operations.size(); ++i) {
            if (IsSumOperation(operations[i])) {
                Sum(stck, result);
                continue;
            }

            if (IsInvalidateOperation(operations[i])) {
                Invalidate(stck, result);
                continue;
            }

            if (IsDoubleOperation(operations[i])) {
                Double(stck, result);
                continue;
            }

            Add(stck, result, operations[i]);
        }

        return result;
    }

    void Double(StackRef stck, IntRef result) {
        stck.push(stck.top() * 2);
        result += stck.top();
    }

    void Sum(StackRef stck, IntRef result) {
        auto popped = stck.top(); stck.pop();
        auto insert = stck.top() + popped;

        stck.push(popped);
        stck.push(insert);
        result += stck.top();
    }

    void Add(StackRef stck, IntRef result, ConstStringRef value) {
        stck.push(std::stoi(value));
        result += stck.top();
    }

    void Invalidate(StackRef stck, IntRef result) {
        result -= stck.top();
        stck.pop();
    }

private:
    bool IsDoubleOperation(ConstStringRef value) const {
        return (value == "D");
    }

    bool IsSumOperation(ConstStringRef value) const {
        return (value == "+");
    }

    bool IsInvalidateOperation(ConstStringRef value) const {
        return (value == "C");
    }
};