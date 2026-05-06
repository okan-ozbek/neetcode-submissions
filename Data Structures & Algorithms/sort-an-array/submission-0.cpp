class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (std::size_t i{ 1 }; i < nums.size(); ++i) {
            std::size_t j{ i - 1 };

            while ((j >= 0) && (nums[j + 1] < nums[j])) {
                swap(nums[j + 1], nums[j]);

                if (j == 0) break;

                --j;
            }
        }

        return nums;
    }

    void swap(int& a, int& b) {
        auto c = a;

        a = b;
        b = c;
    }
};