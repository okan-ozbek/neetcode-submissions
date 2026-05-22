class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) {
            if (i + 1 < nums.size()) {
                std::cout << "i = " << i << " = " << nums[i] % 2 << "\n";
                std::cout << "i + 1 = " << i + 1 << " = " << nums[i + 1] % 2 << "\n";

                if (
                    (nums[i] % 2 == 0 && nums[i + 1] % 2 != 0) || 
                    (nums[i] % 2 != 0 && nums[i + 1] % 2 == 0)
                ) {
                    continue;
                }

                return false;
            }
        }

        return true;
    }
};