class Solution {
public:
    bool isValid(string& s) {
        vector<char> stck{};
        int stckN = 0;
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stck.push_back(c);
                ++stckN;
                continue;
            } else if (stckN > 0 && c == ']' && stck[stckN - 1] == '[') {
                --stckN;
                stck.pop_back();
                continue;
            } else if (stckN > 0 && c == '}' && stck[stckN - 1] == '{') {
                --stckN;
                stck.pop_back();
                continue;
            } else if (stckN > 0 && c == ')' && stck[stckN - 1] == '(') {
                --stckN;
                stck.pop_back();
                continue;
            } else {
                return false;
            }
        }

        for (auto& c : stck) {
            cout << c << endl;
        }

        return stck.size() == 0;
    }
};
