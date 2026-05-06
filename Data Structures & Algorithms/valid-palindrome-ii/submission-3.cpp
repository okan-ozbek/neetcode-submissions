class Solution {
public:
    [[nodiscard]] bool validPalindrome(string s) noexcept {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }

            ++l;
            --r;
        }

        return true;
    }

    [[nodiscard]] bool isPalindrome(const string& s, int l, int r) noexcept {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }

            ++l;
            --r;
        }

        return true;
    }
};