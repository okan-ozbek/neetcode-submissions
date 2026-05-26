class Solution {
public:
    int lengthOfLastWord(string s) {
        int i{0};
        int j{0};
        int n = s.size();

        while (j < n) {
            if (j > 0 && s[j - 1] == ' ' && s[j] != ' ') {
                i = j;
            }
            
            ++j;
        }

        while (s[j - 1] == ' ') {
            --j;
        }

        return j - i;
    }
};