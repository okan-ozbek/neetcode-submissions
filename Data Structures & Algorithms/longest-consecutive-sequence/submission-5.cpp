class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int maxLength{0};

        for (int num : uset) {
            // There is no value on the left (nothing is smaller then one in the array)
            if (uset.find(num - 1) == uset.end()) {
                // Get the sequence length iteratively by checking if there is a value to its right (by 1)
                int currentLength = 0;
                while (uset.find(num + currentLength) != uset.end()) {
                    ++currentLength;
                }

                if (currentLength > maxLength) {
                    maxLength = {currentLength};
                }
            }
        }

        return maxLength;
    }
};
