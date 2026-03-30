class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const auto n = nums.size();

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans{};
        ans.reserve(n/2);

        for(int i{}; i < n - 2; i++) {
            if (nums[i] > 0 || nums[i] + nums[i + 1] + nums[i + 2] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum > 0) {
                    --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    --r;
                    ++l;

                    while (l < r && nums[r] == nums[r + 1]) --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
            }
        }

        return ans;
    }
};
