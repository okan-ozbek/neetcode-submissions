class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        auto min = nums[0];
        auto max = nums[0];

        for (auto& n : nums) {
            min = std::min(min, n);
            max = std::max(max, n);
        }

        return (max - min) == (nums.size() - 1);
    }
};