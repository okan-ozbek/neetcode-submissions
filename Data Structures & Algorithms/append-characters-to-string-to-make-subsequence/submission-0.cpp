class Solution {
public:
    int appendCharacters(string s, string t) {
        int j{}; 

        for(int i{}; i < s.size(); ++i) {
            if (s[i] == t[j]) {
                ++j;
            }
        }

        // for (int i{j}; i < t.size(); ++i) {
        //     s.push_back(t[i]);
        // }

        return t.size() - j;
    }
};