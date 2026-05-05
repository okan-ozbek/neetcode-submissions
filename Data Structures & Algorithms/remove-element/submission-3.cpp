class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::size_t i{};
        for (std::size_t j{}; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }

        return i;
    }
};