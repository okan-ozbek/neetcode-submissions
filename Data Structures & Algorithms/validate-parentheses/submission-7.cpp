class Solution {
public:
    bool isValid(string& s) {
        stack<char> x{};

        for (auto& c : s) {
            if ((c == '(') ||
                (c == '{') ||
                (c == '[')) {
                x.push(c);
            } else {
                if (x.empty()) {
                    return false;
                }

                auto& t = x.top();
                x.pop();

                if ((c == ')' && t != '(') ||
                    (c == '}' && t != '{') ||
                    (c == ']' && t != '[')) {
                    return false;
                }
            }
        }

        return x.empty();
    }
};
