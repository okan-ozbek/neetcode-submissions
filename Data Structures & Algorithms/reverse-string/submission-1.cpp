class Solution {
public:
    void reverseString(vector<char>& s) {
        std::size_t l{}, r{s.size() - 1};

        while (l < r) {
            std::swap(s[l], s[r]);

            ++l;
            --r;
        }
    }
};