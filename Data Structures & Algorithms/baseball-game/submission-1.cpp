class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> s{};

        for (int i{}; i < operations.size(); ++i) {
            if (operations[i] == "+") {
                int popped = s.top(); s.pop();
                int insert = s.top() + popped;

                s.push(popped);
                s.push(insert);

                continue;
            }

            if (operations[i] == "C") {
                s.pop();

                continue;
            }

            if (operations[i] == "D") {
                s.push(s.top() * 2);

                continue;
            }

            s.push(std::stoi(operations[i]));
        }

        int ans{};
        while (s.empty() == false) {
            ans += s.top(); s.pop();
        }

        return ans;
    }
};