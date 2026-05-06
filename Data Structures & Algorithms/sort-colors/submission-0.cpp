class Solution {
public:
    void sortColors(vector<int>& nums) {
        bool sorted = false;

        do {
            sorted = true;

            for (std::size_t i{1}; i < nums.size(); ++i) {
                if (nums[i - 1] > nums[i]) {
                    auto temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;

                    sorted = false;
                }
            }
        } 
        while(sorted == false);
    }
};