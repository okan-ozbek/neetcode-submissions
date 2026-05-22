class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag{};

        for (auto& chr : magazine) {
            ++mag[chr];
        }

        for (auto& chr : ransomNote) {
            auto it = mag.find(chr);
            if (it != mag.end() && it->second > 0) {
                --it->second;    
            } else {
                return false;
            }
            
        }

        return true;
    }
};