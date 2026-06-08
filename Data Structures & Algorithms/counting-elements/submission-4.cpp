class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_map<int, int> items{};
        int count{};

        for (auto& x : arr) {
            items[x]++;
        }

        for (auto& x : arr) {
            if (items.find(x + 1) == items.end()) {
                continue;
            }

            ++count;
        }

        return count;
    }
};
