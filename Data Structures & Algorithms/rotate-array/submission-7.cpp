class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int curr;
        int temp;

        for (int i = 0; i < k; ++i) {
            curr = nums[n - 1];
            for (int j = 0; j < n; ++j) {
                temp = nums[j];
                nums[j] = curr;
                curr = temp;
            }
        }
    }
};