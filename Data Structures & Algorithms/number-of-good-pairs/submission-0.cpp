class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs{};
        for (int i{}; i < nums.size(); ++i) {
            for (int j{i + 1}; j < nums.size(); ++j) {
                if (nums[i] == nums[j] && i < j) {
                    ++pairs;
                }
            }
        }   

        return pairs;
    }
};