class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::vector seen(nums.size(), 0);

        for(int x : nums) {
            seen[x]++;
            if (seen[x] >= 2) {
                return x;
            } 
        }

        return -1;
    }
};
