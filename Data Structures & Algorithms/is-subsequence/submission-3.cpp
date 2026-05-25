class Solution {
public:
    bool isSubsequence(const string& substr, const string& fullstr) {
        int i_substr{}, i_fullstr{};
        while (i_fullstr < fullstr.size()) {
            if (substr[i_substr] == fullstr[i_fullstr]) {
                ++i_substr;    
            } 

            ++i_fullstr;
        }

        return i_substr == substr.size();
    }
};