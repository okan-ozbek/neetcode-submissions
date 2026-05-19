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

    // int minSubArrayLen(int target, vector<int>& nums) {
    //     if (nums.size() == 1) return (nums[0] >= target);
    //     if (nums[0] >= target) return 1;

    //     int left{}, right{1}, subsize{}, currentValue{};

    //     currentValue = nums[left] + nums[right];

    //     while (left <= right && right < nums.size()) {
    //         if (currentValue >= target) {

    //             subsize = (subsize == 0) 
    //                 ? subsize = (right - left) + 1
    //                 : std::min(subsize, (right - left) + 1);

    //             currentValue -= nums[left];
    //             ++left;

    //             continue;
    //         } 

    //         ++right;
    //         if (right >= nums.size()) {
    //             break;
    //         }
    //         currentValue += nums[right];
    //     }

    //     return subsize;
    // }
};