class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups{};

        for(string str : strs) {
            vector<int> asciiFreq(26, 0);
            for (char& chr : str) {
                ++asciiFreq[static_cast<int>(chr) - 97];
            }

            string key{};
            for (int& count : asciiFreq) {
                key += count;
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> result{};
        for(auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};