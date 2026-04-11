class Solution {
public:
    // Attempt 1
    // bool isAnagram(string s, string t) {
    //     if (s.length() != t.length()) {
    //         return false;
    //     }

    //     std::unordered_map<char, int> ums;
    //     std::unordered_map<char, int> umt;

    //     for(char c : s) {
    //         ums[c]++;
    //     }

    //     for(char c : t) {
    //         umt[c]++;
    //     }

    //     return ums == umt;
    // }

    // Low-latency attempt
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::vector<int> v(26, 0);

        for (int i{}; i < s.size(); ++i) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for (int n : v) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
};
