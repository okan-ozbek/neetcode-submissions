class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i{};
        int j{ 1 };

        while (std::abs(i - j) <= k && j < nums.size()) {
            if (nums[i] == nums[j]) {
                return true;
            }

            if (j < i + k) {
                ++j;
            } else {
                ++i;
                j = i + 1;
            }
        }

        return false;

    }
};