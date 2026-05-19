class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 1) {
            return (nums[0] >= target);
        }

        if (nums[0] >= target) {
            return 1;
        }

        int l{}, r{1}, s{}, c{};

        c = nums[l] + nums[r];

        while (r < nums.size()) {
            if (c >= target) {

                s = (s == 0) 
                    ? s = (r - l) + 1
                    : std::min(s, (r - l) + 1);

                c -= nums[l];
                ++l;

                continue;
            } 

            ++r;
            if (r >= nums.size()) {
                break;
            }
            c += nums[r];
        }

        return s;
    }
};