class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq{};

        for (const auto& num : nums) {
            freq[num]++;
        }

        std::vector<int> res(k);
        
        while (k != 0) {
            std::pair<int, int> kv{ 0, 0 };

            for (const auto& [key, value] : freq) {
                if (value > kv.second) {
                    kv.first = { key };
                    kv.second = { value };
                }
            }

            res[res.size() - k] = kv.first;
            freq.erase(kv.first);

            --k;
        }
        
        return res;
    }
};
