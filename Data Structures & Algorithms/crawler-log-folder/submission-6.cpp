class Solution {
public:
    int minOperations(const vector<string>& logs) noexcept {
        int res{};

        for (auto& x : logs) {
            if (x == "../") {
                res = std::max(0, --res);
            }
            else if (x != "./") {
                ++res;
            }
        }

        return res;
    }
};