class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> um{};
        int l{0}, res{0};

        for(int r{}; r < s.size(); ++r) {
            if (um.find(s[r]) != um.end()) {
                l = std::max(um[s[r]] + 1, l);
            } 
            
            um[s[r]] = r;
            res = std::max(res, r - l + 1);
        }

        return res;
    }   

    // int lengthOfLongestSubstring(string s) {
    //     std::unordered_map<char, int> u_map{};
    //     int left{}, result{};

    //     for (int right{}; right < s.size(); ++right) {
    //         if (u_map.find(s[right]) != u_map.end()) {
    //             if (left < right) { 
    //                 left = u_map[s[right]] + 1;
    //             }
    //         }

    //         u_map[s[right]] = right;

    //         if (right - left + 1 > result) {
    //             result = right - left + 1;
    //         } 
    //     }

    //     return result;
    // }
};
