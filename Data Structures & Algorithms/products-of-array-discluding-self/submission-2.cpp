class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results{};

        for(int i{}; i < n; i++) {
            int sum{1};

            for (int j{}; j < n; j++) {
                if (j == i) {
                    continue;
                }

                sum *= nums[j];
            }

            results.push_back(sum);
        }

        return results;
    }
};
