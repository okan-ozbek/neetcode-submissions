class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l{1};
        int r{*std::max_element(piles.begin(), piles.end())};
        int res{r};

        while (l <= r) {
            int k = l + ((r - l) / 2);

            int t{};
            for (auto& p : piles) {
                t += std::ceil(static_cast<double>(p) / k);
            }

            if (t > h) {
                l = k + 1;
            } else {
                res = k;
                r = k - 1;
            }
        }

        return res;
    }
};
