class Solution {
public:
    vector<int> majorityElement(const vector<int>& nums) {
        std::unordered_map<int, int> um{};
        std::vector<int> res{};

        for(int i{0}; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        for(auto& x : um) {
            if (x.second > nums.size() / 3) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};