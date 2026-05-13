class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> stack{}; 
        int result{};

        for (int i{}; i < operations.size(); ++i) {
            if (operations[i] == "+") {
                int popped = stack.top(); stack.pop();
                int insert = stack.top() + popped;

                stack.push(popped);
                stack.push(insert);
                result += stack.top();

                continue;
            }

            if (operations[i] == "C") {
                result -= stack.top();
                stack.pop();

                continue;
            }

            if (operations[i] == "D") {
                stack.push(stack.top() * 2);
                result += stack.top();

                continue;
            }

            stack.push(std::stoi(operations[i]));
            result += stack.top();
        }

        

        return result;
    }
};