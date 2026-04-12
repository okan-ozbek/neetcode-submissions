class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um{};

        for(int i{}; i < nums.size(); i++) {
            if (um.find(target - nums[i]) != um.end()) {
                vector<int> v{};
                v.push_back(um[target - nums[i]]);
                v.push_back(i);

                return v;
            }

            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = i;
            }
        }
    }
};
