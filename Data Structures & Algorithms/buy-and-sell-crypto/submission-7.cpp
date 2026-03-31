class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l{0}, r{0}, max{0};

        while (r < prices.size()) {
            if (prices[l] < prices[r])  {
                int sum = prices[r] - prices[l];
                max = (max > sum) ? max : sum;
            } else {
                l = r;
            }
            ++r;
        }

        return max;
    }
};
