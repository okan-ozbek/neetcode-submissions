class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap{};

        for(int i{}; i < nums.size(); ++i) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                return {
                    hashmap[target - nums[i]], 
                    i
                };
            }

            if (hashmap.find(nums[i]) == hashmap.end()) {
                hashmap[nums[i]] = i;
            }
        }
    }
};
