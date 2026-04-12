class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if (sn != tn)
            return false;

        std::vector<short> v(26, 0);

        for (int i{}; i < sn; ++i) {
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
