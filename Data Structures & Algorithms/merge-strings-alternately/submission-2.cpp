class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int i{}, j{};

        std::string word{};

        while(i < n || j < m) {
            if (i < n) { word += word1[i++]; }
            if (j < m) { word += word2[j++]; }
        }

        return word;
    }
};