class Solution {
public:
    string simplifyPath(string path) {
        std::vector<string> items{};
        std::string current{};

        for (char chr : path + "/") {
            if (chr == '/') {
                if (current == "..") {
                    if (items.empty() == false) {
                        items.pop_back();
                    }
                }
                else if (current.empty() == false && current != ".") {
                    items.push_back(current);
                }

                current.clear();
            } else {
                current += chr;
            }
        }

        current.clear();
        current += "/";
        for (int i{}; i < items.size(); ++i) {
            if (i > 0) {
                current += "/";
            }
            
            current += items[i];
        }

        return current;
    }
};