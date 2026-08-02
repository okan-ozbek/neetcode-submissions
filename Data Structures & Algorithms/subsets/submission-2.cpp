class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> current_subset{};
        std::vector<std::vector<int>> subsets{};

        helper(0, nums, current_subset, subsets);

        return subsets;
    }

    void helper(const int index, const std::vector<int>& nums, vector<int>& current_subset, vector<vector<int>>& subsets) {
        if (index >= nums.size()) {
            subsets.push_back(current_subset);
            return;
        }

        current_subset.push_back(nums[index]);
        helper(index + 1, nums, current_subset, subsets);
        current_subset.pop_back();

        helper(index + 1, nums, current_subset, subsets);
    }
};
