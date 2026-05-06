class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res{};
        int highest{};
        std::unordered_map<int, int> hashmap{};

        for (const auto& x : nums) {
            ++hashmap[x];
            
            if (hashmap[x] > highest) {
                res = x;
                highest = hashmap[x];
            }
        }

        return res;
    }
};