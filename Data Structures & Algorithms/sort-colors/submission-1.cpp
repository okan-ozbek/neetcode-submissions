class Solution {
public:
    void sortColors(vector<int>& nums) {
        bool sorted = false;

        do {
            sorted = true;

            for (std::size_t i{1}; i < nums.size(); ++i) {
                if (nums[i - 1] > nums[i]) {
                    swap(nums[i - 1], nums[i]);
                    sorted = false;
                }
            }
        } 
        while(sorted == false);
    }

    void swap(int& a, int& b) {
        auto c = a;
        a = b;
        b = c;
    }
};