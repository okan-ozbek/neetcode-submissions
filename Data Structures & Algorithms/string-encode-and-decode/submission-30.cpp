class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded{};

        for(const string& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        std::vector<string> res{};
        int offset{0};

        while (offset < s.length()) {
            int numLength{offset};

            while(s[numLength] != '#') {
                ++numLength;
            }

            int wordLength{std::stoi(s.substr(offset, numLength - offset))};
            std::cout << wordLength << std::endl;

            res.push_back(s.substr(numLength + 1, wordLength));
            offset = numLength + 1 + wordLength;
        }

        return res;
    }
};
