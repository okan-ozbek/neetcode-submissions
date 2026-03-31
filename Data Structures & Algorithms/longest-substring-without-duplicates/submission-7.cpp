class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int l{0}, r{0}, max{0};
        std::vector<int> c{};

        while(r < s.size()) {
            if (std::find(c.begin(), c.end(), s[r]) != c.end()) {
                int n = c.size();
                if (n > max) {
                    max = n;
                }
                c.erase(c.begin());
                ++l;
            } else {
                c.push_back(s[r]);
                ++r;

            }
        }

        int n = c.size();
        if (n > max) {
            max = n;
        }
        return max;
    }
};
