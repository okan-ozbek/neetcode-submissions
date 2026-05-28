class Solution {
public:
    int appendCharacters(string s, string t) {
        int j{}; 

        for(int i{}; i < s.size(); ++i) {
            if (s[i] == t[j]) {
                ++j;
            }
        }

        return t.size() - j;
    }
};