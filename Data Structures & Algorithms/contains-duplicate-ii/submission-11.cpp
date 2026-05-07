class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> um{};

        for (int i{}; i < nums.size(); ++i) {
            if (um.find(nums[i]) != um.end() && um[nums[i]] >= i - k) {
                return true;
            }

            um[nums[i]] = i;
        }

        return false;
    }
};