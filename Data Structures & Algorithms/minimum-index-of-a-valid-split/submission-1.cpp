class Solution {
public:
    using FreqMap = std::unordered_map<int, int>;
    using Size = std::size_t;

    int minimumIndex(vector<int>& nums) {
        FreqMap freq_left{};
        FreqMap freq_right{};
        Size n = nums.size();

        for (auto& value : nums) {
            ++freq_right[value];
        }

        for (auto i{ 0uz }; i < n; ++i) {
            ++freq_left[nums[i]];
            --freq_right[nums[i]];

            auto n_left = i + 1;
            auto n_right = n - i - 1;

            if (freq_left[nums[i]] * 2 > n_left && freq_right[nums[i]] * 2 > n_right) {
                return i;
            }
        }

        return -1;
    }
};