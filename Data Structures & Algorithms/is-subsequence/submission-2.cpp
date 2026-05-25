class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ti{}, si{};
        while (ti < t.size()) {
            if (s[si] == t[ti]) {
                ++si;    
            } 

            ++ti;
        }

        return si == s.size();
    }
};