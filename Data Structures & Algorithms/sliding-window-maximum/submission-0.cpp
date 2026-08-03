class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l{ 0 }, r{ k };
        std::vector<int> result{};

        while (r <= nums.size()) {
            auto max{ nums[l] };
            for (std::size_t i{}; i < k; ++i) {
                if (max < nums[l + i]) {
                    max = nums[l + i];
                }
            }
            result.push_back(max);
            ++l;
            ++r;
        }

        return result;
    }
};
