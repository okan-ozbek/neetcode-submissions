class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> values{};

        int first{};
        int second{};

        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                second = values.top(); values.pop();
                first  = values.top(); values.pop();

                if (token == "+") {
                    values.push(first + second);
                }
                else if (token == "-") {
                    values.push(first - second);
                }
                else if (token == "*") {
                    values.push(first * second);
                }
                else if (token == "/") {
                    values.push(first / second);
                }
            } else {
                values.push(std::stoi(token));
            }
        }

        return values.top();
    }
};
