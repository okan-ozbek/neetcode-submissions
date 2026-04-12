class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> results{};

    //     for(int i{}; i < n; ++i) {
    //         int sum{1};

    //         for (int j{}; j < n; ++j) {
    //             if (j == i) {
    //                 continue;
    //             }

    //             sum *= nums[j];
    //         }

    //         results.push_back(sum);
    //     }

    //     return results;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n{nums.size()};
        vector<int> res(n, 1);

        for (int i{1}; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i{n - 1}; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
