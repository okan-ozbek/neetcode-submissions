class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_set<int> items{};
        int count{};

        for (auto& x : arr) items.insert(x);
        for (auto& x : arr) {
            if (items.find(x + 1) == items.end()) continue;
            ++count;
        }

        return count;
    }
};
