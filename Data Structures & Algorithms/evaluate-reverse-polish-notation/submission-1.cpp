class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stck{};

        for (auto& token : tokens) {
            int a{};
            int b{};

            if (token == "+") {
                b = stck.top(); stck.pop();
                a = stck.top(); stck.pop();

                stck.push(a + b);
            } else if (token == "-") {
                b = stck.top(); stck.pop();
                a = stck.top(); stck.pop();

                stck.push(a - b);
            } else if (token == "*") {
                b = stck.top(); stck.pop();
                a = stck.top(); stck.pop();

                stck.push(a * b);
            } else if (token == "/") {
                b = stck.top(); stck.pop();
                a = stck.top(); stck.pop();
                
                stck.push(a / b);
            } else {
                stck.push(std::stoi(token));
            }
        }

        return stck.top();
    }
};
