class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res{};
        int highest{};
        std::unordered_map<int, int> hashmap{};

        for (const auto& x : nums) {
            ++hashmap[x];
        }

        for (const auto& [key, value] : hashmap) {
            if (value > highest) {
                res = key;
                highest = value;
            }
        }

        return res;
    }
};