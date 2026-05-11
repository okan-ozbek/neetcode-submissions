class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::unordered_map<char, int> um1{};
        std::unordered_map<char, int> um2{};

        for (char& c : s1) {
            um1[c]++;
        }

        for (int i{}; i < s1.size(); i++) {
            um2[s2[i]]++;
        }

        if (um1 == um2) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            um2[s2[i]]++;

            char left = s2[i - s1.size()];
            um2[left]--;

            if (um2[left] == 0) {
                um2.erase(left);
            }

            if (um1 == um2) {
                return true;
            }
        }

        return false;
    }
};
