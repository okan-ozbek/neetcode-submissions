class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans{};
        const auto n = nums.size();

        for(int i{}; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum{nums[i] + nums[l] + nums[r]};

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

                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                }
            }
        }

        return ans;
    }
};
