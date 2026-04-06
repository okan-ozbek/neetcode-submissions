class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur{};
        int max{};

        for (int i{}; i < nums.size(); i++) {
            if (i == 0 && nums[i] == 1) {
                cur++;
                continue;
            }

            if (nums[i] != 1) {
                if (cur > max) {
                    max = cur;
                }

                cur = 0;
                continue;
            } 
            
            cur++;
        }

        return (cur > max) ? cur : max;
    }
};