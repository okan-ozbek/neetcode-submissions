class Solution {
public:
    using SizeType = std::size_t;
    using String = std::string;
    using StringVector = std::vector<std::string>;

    String longestCommonPrefix(const StringVector& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        String ans{};
        SizeType stringIdx{1};
        SizeType letterIdx{0};
        
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