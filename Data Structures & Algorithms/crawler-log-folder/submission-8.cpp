class Solution {
public:
    int minOperations(const std::vector<std::string>& logs) noexcept {
        int res{};

        for (const auto& log : logs) {
            if (log == "../") {
                if (res > 0) --res;
            }
            else if (log != "./") {
                ++res;
            }
        }

        return res;
    }
};