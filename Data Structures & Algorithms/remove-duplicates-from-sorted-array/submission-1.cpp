class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;

        while (r < nums.size()) {
            if (nums[l] != nums[r]) {
                ++l;
                ++r;
            } else {
                nums.erase(nums.begin() + r);
            }
        }

        return nums.size();
    }
};