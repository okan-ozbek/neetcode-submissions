class Solution {
public:
    std::string removeVowels(std::string s) {
        std::unordered_map<char, int> vowels{ 
            { 'a', 0 },
            { 'o', 0 },
            { 'u', 0 },
            { 'i', 0 },
            { 'e', 0 },
        };

        std::string res{};

        for (int i{}; i < s.size(); ++i) {
            if (vowels.contains(s[i])) {
                continue;
            }

            res.push_back(s[i]);
        }

        return res;
    }
};
