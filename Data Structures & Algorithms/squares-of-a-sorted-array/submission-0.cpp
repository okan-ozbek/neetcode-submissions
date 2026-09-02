class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (std::size_t i{}; i < nums.size(); ++i) {
            nums[i] = std::abs(nums[i]) * std::abs(nums[i]);
        }

        std::sort(nums.begin(), nums.end());

        return nums;
    }
};