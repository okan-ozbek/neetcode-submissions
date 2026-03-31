class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIndex{0};
        int sellIdex{0};

        int maxProfit{0};

        while (buyIndex < prices.size() && sellIdex < prices.size()) {
            if (prices[buyIndex] > prices[sellIdex]) {
                buyIndex++;
            } else if (prices[buyIndex] < prices[sellIdex]) {
                int currentSell{prices[sellIdex] - prices[buyIndex]};

                if (maxProfit < currentSell) {
                    maxProfit = currentSell;
                }

                sellIdex++;
            } else {
                sellIdex++;
            }
        }

        return maxProfit;
    }
};
