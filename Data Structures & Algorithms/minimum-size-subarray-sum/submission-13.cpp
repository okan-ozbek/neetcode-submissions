class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i{};
        int j{};
        int sum{};
        int ans{ INT_MAX };

        while (j < nums.size()) {
            sum += nums[j];

            while (sum >= target) {
                ans = std::min(ans, j - i + 1);
                sum -= nums[i];
                ++i;
            }

            ++j;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};