class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::cout << nums.size() << std::endl;
        std::unordered_map<int, int> hashmap;

        for (int num : nums) {
            ++hashmap[num];

            if (hashmap[num] >= 2) 
                return true;
        }

        return false;
    }
};