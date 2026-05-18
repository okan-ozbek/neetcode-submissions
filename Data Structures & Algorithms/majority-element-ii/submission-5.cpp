class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int calc{ n / 3 }; 
        std::unordered_map<int, int> um{};

        for(int i{}; i < n; ++i) {
            ++um[nums[i]];
        }

        std::vector<int> res{};
        for(auto& x : um) {
            if (x.second > calc) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};