class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int low = nums[0];
        int high = nums[0];
        //std::sort(nums.begin(), nums.end());   
        std::unordered_map<int, int> res{};

        for (auto& n : nums) {
            res[n]++;
            if (res[n] > 1) {
                return false;
            }

            low = std::min(low, n);
            high = std::max(high, n);
        }

        return high - low == nums.size() - 1;
    }
};