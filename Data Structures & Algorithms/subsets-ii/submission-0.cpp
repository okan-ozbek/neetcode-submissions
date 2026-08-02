class Solution {
public:
    using Subsets = std::vector<std::vector<int>>;
    using IntArray = std::vector<int>;

    Subsets subsetsWithDup(IntArray& nums) {
        std::sort(nums.begin(), nums.end());

        Subsets subsets;
        IntArray current_subset;

        helper(0, nums, current_subset, subsets);

        return subsets;
    }

    void helper(
        int index, 
        const IntArray& nums, 
        IntArray& current_subset, 
        Subsets& subsets
    ) {
        if (index >= nums.size()) {
            subsets.push_back(current_subset);
            return;
        }

        current_subset.push_back(nums[index]); // Add to subset
        helper(index + 1, nums, current_subset, subsets); // Recurse

        current_subset.pop_back(); // Remove from subset

        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) {
            ++index;
        }

        helper(index + 1, nums, current_subset, subsets); // Decision without the value
    }
};
