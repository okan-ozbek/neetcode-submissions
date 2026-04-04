class Solution {
public:
    bool isValid(string& s) {
        vector<char> stck{};
        int stckN = 0;
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stck.push_back(c);
            }
            else {
                if (stck.size() == 0) return false;

                char tc = stck[stck.size() - 1];
                stck.pop_back();

                if ((c == ')' && tc != '(') ||
                    (c == '}' && tc != '{') ||
                    (c == ']' && tc != '[')) {
                    return false;
                }
            }
        }

        return stck.size() == 0;
    }
};
