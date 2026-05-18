class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::size_t n{ nums.size() };
        std::unordered_map<int, int> um{};

        for(std::size_t i{}; i < n; ++i) {
            ++um[nums[i]];
        }

        std::vector<int> res{};
        for(auto& [key, count] : um) {
            if (count > n / 3) {
                res.push_back(key);
            }
        }

        return res;
    }
};