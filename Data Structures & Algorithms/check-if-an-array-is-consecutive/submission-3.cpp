class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());   
        std::unordered_map<int, int> res{};

        for (auto& n : nums) {
            res[n]++;
            if (res[n] > 1) {
                return false;
            }
        }

        for (int i{ 1 }; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                return false;
            }
        }

        return true;
    }
};
