class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int l{ -1 };
        std::unordered_map<int, int> m{};

        for (auto& x : nums) {
            ++m[x];
        }
        
        for (auto& [k, v] : m) {
            if (l < k && v == 1) {
                l = k;
            }
        }

        return l;
    }
};
