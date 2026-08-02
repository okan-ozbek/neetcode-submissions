class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(0, nums);
    }

    vector<vector<int>> helper(const int index, const vector<int>& nums) {
        if (index >= nums.size()) {
            return {{}};
        }

        vector<vector<int>> result{};

        vector<vector<int>> perms = helper(index + 1, nums);
        for (auto& perm : perms) {
            for (std::size_t i{}; i < perm.size() + 1; ++i) {
                vector<int> perm_copy = perm;
                perm_copy.insert(perm_copy.begin() + i, nums[index]);
                result.push_back(perm_copy);
            }
        }

        return result;
    }
};
