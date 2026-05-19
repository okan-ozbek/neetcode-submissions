class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 1) return (nums[0] >= target);
        if (nums[0] >= target) return 1;

        int left{}, right{1}, subsize{}, currentValue{};

        currentValue = nums[left] + nums[right];

        while (right < nums.size()) {
            if (currentValue >= target) {

                subsize = (subsize == 0) 
                    ? subsize = (right - left) + 1
                    : std::min(subsize, (right - left) + 1);

                currentValue -= nums[left];
                ++left;

                continue;
            } 

            ++right;
            if (right >= nums.size()) {
                break;
            }
            currentValue += nums[right];
        }

        return subsize;
    }
};