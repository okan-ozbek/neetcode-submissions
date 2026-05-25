class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ti{0};
        int si{0};
        while (ti < t.size()) {
            if (s[si] == t[ti]) {
                std::cout << "Called" << std::endl;

                ++si;
                ++ti;
            } else {
                std::cout << "Called 2" << std::endl;
                ++ti;
            }
        }

        return si == s.size();
    }
};