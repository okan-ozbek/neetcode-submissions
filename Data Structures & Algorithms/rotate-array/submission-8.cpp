class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int curr;
    //     int temp;

    //     for (int i = 0; i < k; ++i) {
    //         curr = nums[n - 1];
    //         for (int j = 0; j < n; ++j) {
    //             temp = nums[j];
    //             nums[j] = curr;
    //             curr = temp;
    //         }
    //     }
    // }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> v(n, 0);

        for(int i{}; i < n; ++i) {
            v[(i + k) % n] = nums[i];
        }

        nums = std::move(v);
    }
};