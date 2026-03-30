class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> um;

        for (int x : nums) {
            um[x]++;
            if (um[x] >= 2) {
                return true;
            }
        }

        return false;
    }
};