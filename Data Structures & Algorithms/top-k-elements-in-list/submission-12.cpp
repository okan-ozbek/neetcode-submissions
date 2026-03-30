class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency{};
        for(int number : nums) {
            frequency[number]++;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for(auto& [keyNumber, valueOccurrence] : frequency) {
            bucket[valueOccurrence].push_back(keyNumber);
        }

        std::vector<int> result{};
        for(int i{ bucket.size() - 1 }; i > 0; i--) {
            //for (int j{}; j < bucket[i].size(); j++) {
            for(int x : bucket[i]) {
                result.push_back(x);

                if (result.size() >= k) {
                    return result;
                }
            }
        }
    }
};
