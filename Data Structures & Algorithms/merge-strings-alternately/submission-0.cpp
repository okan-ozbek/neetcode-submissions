class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n{}, m{};
        bool firstTurn{ true };

        std::string newWord{};

        while(n < word1.size() && m < word2.size()) {
            if (firstTurn) {
                newWord.push_back(word1[n]);
                ++n;
            } else {
                newWord.push_back(word2[m]);
                ++m;
            }

            firstTurn = !firstTurn;
        }

        while (n < word1.size()) {
            newWord.push_back(word1[n]);
            ++n;
        }

        while (m < word2.size()) {
            newWord.push_back(word2[m]);
            ++m;
        }

        return newWord;
    }
};