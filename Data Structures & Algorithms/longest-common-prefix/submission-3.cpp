class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        std::string ans{};
        
        std::size_t stringIdx{1};
        std::size_t letterIdx{0};
        while (strs[stringIdx][letterIdx] == strs[stringIdx - 1][letterIdx]) {
            if (letterIdx >= strs[stringIdx].size()) {
                return ans;
            }

            if (stringIdx == (strs.size() - 1)) {
                ans.push_back(strs[stringIdx][letterIdx]);
                ++letterIdx;
                stringIdx = 0;
            }

            ++stringIdx;
        }

        return ans;
    }
};