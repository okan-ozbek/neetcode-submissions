class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::unordered_map<int, int> c{};
        for (auto& x : s) {
            ++c[x];
        }

        int sc{};
        for (auto& [k, v] : c) {
            if (v % 2 == 1) {
                if (sc >= 1) {
                    return false;
                }
                ++sc;
            }
        }

        return true;
    }
};
