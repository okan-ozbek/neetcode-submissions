class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res{};
        for (string& x : logs) {
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