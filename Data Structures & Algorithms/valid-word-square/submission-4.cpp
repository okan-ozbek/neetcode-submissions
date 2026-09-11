class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (std::size_t i{}; i < words.size(); ++i) {
            for (std::size_t j{}; j < words[i].size(); ++j) {
                if (words.size() <= j || words[j].size() <= i) {
                    return false;
                }

                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
