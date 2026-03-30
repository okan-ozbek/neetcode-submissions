class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans{};

        int n = nums.size();
        int left{1};
        int right{n};

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            left = i + 1; 
            right = n - 1;
            while (left < right) {
                int sum{nums[i] + nums[left] + nums[right]};
                
                if (sum > 0) {
                    --right;
                }
                else if (sum < 0) {
                    ++left;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    // Find non-dupe
                    while(left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                }
            }
        }

        return ans;
    }
};
