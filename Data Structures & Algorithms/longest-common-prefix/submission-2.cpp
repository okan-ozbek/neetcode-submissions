class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        std::string ans{};
        
        int i{1};
        int check{0};
        while (strs[i][check] == strs[i - 1][check]) {
            if (check >= strs[i].size()) {
                return ans;
            }

            if (i == (strs.size() - 1)) {
                ans.push_back(strs[i][check]);
                ++check;
                i = 0;
            }

            ++i;
        }

        return ans;
    }
};