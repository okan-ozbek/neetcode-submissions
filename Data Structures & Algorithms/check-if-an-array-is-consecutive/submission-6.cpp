class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int low = nums[0];
        int high = nums[0];

        for (auto& n : nums) {
            low = std::min(low, n);
            high = std::max(high, n);
        }

        return high - low == nums.size() - 1;
    }
};