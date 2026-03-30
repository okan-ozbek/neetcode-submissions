class Solution {
public:
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

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::vector<int> v1(26, 0);
        std::vector<int> v2(26, 0);

        for (char c : s) {
            v1[c - 'a']++;
        }

        for (char c : t) {
            v2[c - 'a']++;
        }

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    }
};
