class Solution {
public:
    bool canPermutePalindrome(const std::string& s) {
        std::unordered_map<char, int> counts{};
        for (auto& x : s) {
            ++counts[x];
        }

        int middleCount{};
        for (auto& [key, val] : counts) {
            if (val % 2 == 1) {
                if (middleCount >= 1) return false;
                ++middleCount;
            }
        }

        return true;
    }
};
