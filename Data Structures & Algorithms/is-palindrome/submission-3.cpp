class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        size_t left = 0;
        size_t right = n - 1;
        
        while(left < n / 2) {
            if (isalnum(s[left]) == 0) {
                ++left;
                continue;
            }

            if (isalnum(s[right]) == 0) {
                --right;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
