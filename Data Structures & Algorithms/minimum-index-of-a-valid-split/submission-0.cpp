class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // [2,1,3,1,1,1,7,1,2,1]
        // [3,3,3,3,7,2,2]

        std::unordered_map<int, int> freq_left{};
        std::unordered_map<int, int> freq_right{};

        for (auto& value : nums) {
            ++freq_right[value];
        }

        for (auto i{ 0uz }; i < nums.size(); ++i) {
            ++freq_left[nums[i]];
            --freq_right[nums[i]];

            auto n_left = i + 1;
            auto n_right = nums.size() - i - 1;

            if (freq_left[nums[i]] * 2 > n_left && freq_right[nums[i]] * 2 > n_right) {
                return i;
            }
        }

        return -1;
    }
};