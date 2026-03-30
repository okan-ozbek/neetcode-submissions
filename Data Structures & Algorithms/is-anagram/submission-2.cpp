class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> ums;
        std::unordered_map<char, int> umt;

        for(char c : s) {
            ums[c]++;
        }

        for(char c : t) {
            umt[c]++;
        }

        return ums == umt;
    }
};
