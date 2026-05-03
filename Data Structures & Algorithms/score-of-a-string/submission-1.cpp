class Solution {
public:
    int scoreOfString(string s) {
        int score{};
        for (std::size_t i{1}; i < s.size(); ++i) {
            score += std::abs(s[i] - s[i - 1]);
        }
        return score;
    }
};