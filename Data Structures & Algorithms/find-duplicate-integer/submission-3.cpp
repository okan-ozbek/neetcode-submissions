class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n{nums.size()};
        std::vector seen(n, 0);

        for(int i{}; i < n; ++i) {
            seen[nums[i]]++;
            if (seen[nums[i]] > 1) return nums[i];
        }

        return -1;

        // for(int x : nums) {
        //     seen[x]++;
        //     if (seen[x] >= 2) {
        //         return x;
        //     } 
        // }

        // return -1;
    }
};
