class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res{};
        for (string& x : logs) {
            if (x == "../") {
                if (res > 0) {
                    --res;
                }
                std::cout << "Deducting, new: " << res << "\n";
                continue;
            }

            if (x == "./") {
                std::cout << "./, skipping\n";
                continue;
            }

            ++res;
            std::cout << "Adding, new: " << res << "\n";
        }

        return res > 0 ? res : 0;
    }
};