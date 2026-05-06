class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n{}, m{};
        bool firstTurn{ true };

        std::string newWord{};

        while(n < word1.size() || m < word2.size()) {
            if (n < word1.size()) {
                newWord += word1[n++];
            }

            if (m < word2.size()) {
                newWord += word2[m++];
            }
        }

        return newWord;
    }
};