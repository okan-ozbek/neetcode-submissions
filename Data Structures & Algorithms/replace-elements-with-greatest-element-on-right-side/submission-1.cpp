class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::size_t n{ arr.size() };
        std::vector<int> ans(n);

        int val{ -1 };
        for (std::size_t i{}; i < n; ++i) {
            std::size_t idx{ n - i - 1 };

            ans[idx] = val;
            val = std::max(val, arr[idx]);
        }

        return ans;
    }
};