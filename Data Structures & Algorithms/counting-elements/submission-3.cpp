class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_map<int, int> items{};
        int count{};

        for (auto& x : arr) {
            items[x]++;
        }

        for (std::size_t i{}; i < arr.size(); ++i) {
            if (items.find(arr[i] + 1) == items.end()) {
                continue;
            }

            ++count;
        }

        return count;
    }
};
