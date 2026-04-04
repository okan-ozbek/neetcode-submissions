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
};
