class Solution {
public:
    int lengthOfLastWord(string s) {
        int i{0};
        int j{0};

        while (j < s.size()) {
            if (j > 0 && s[j - 1] == ' ' && s[j] != ' ') {
                i = j;
            };
            ++j;
        }

        j = (j == s.size()) ? j - 1 : j;
        while (s[j] == ' ') {
            --j;
        }

        return j - i + 1;
    }
};