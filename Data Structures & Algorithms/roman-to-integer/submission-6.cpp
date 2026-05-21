class Solution {
public:
    int romanToInt(const string& s) {
        unordered_map<char, int> um = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 } 
        };

        int n = s.size();
        int res{};
        for (int i{}; i < n; ++i) {
            if (i + 1 != n && um[s[i]] < um[s[i + 1]]) {
                res -= um[s[i]];
            }
            else {
                res += um[s[i]];
            }
        }

        return res;
    }
};