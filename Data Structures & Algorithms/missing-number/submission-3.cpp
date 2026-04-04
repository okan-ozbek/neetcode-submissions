class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::vector x(nums.size(), 0);

        for (auto& n : nums) {
            ++x[n];
        }

        for (int i{}; i < x.size(); i++) {
            if (x[i] == 0) {
                return i;
            }
        }

        return x.size();
    }

    // int missingNumber(vector<int>& nums) {
    //     std::sort(nums.begin(), nums.end());

    //     if (nums[0] != 0) {
    //         return 0;
    //     }

    //     for(int i = {1}; i < nums.size(); i++) {
    //         int diff = nums[i] - nums[i - 1];
    //         if (diff >= 2) {
    //             return nums[i - 1] + 1;
    //         }
    //     }

    //     return nums[nums.size() - 1] + 1;
    // }
};
