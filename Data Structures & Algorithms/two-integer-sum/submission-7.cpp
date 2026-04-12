class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um{};

        for(int i{}; i < nums.size(); ++i) {
            if (um.find(target - nums[i]) != um.end()) {

                return {um[target - nums[i]], i};
            }

            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = i;
            }
        }
    }
};
