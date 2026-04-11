class Solution {
public:
    bool isAnagram(string s, string t) {


        if (s.size() != t.size()) {
            return false;
        }

        std::vector<short> v(26, 0);

        for (int i{}; i < s.size(); ++i) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for (short& n : v) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
};
