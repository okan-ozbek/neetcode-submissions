class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::size_t n{nums.size()};
        vector<int> ans(n * 2, 0);

        for (std::size_t i{}; i < n * 2; ++i) {
            ans[i] = nums[i % n];
        }

        return ans;
    }
};