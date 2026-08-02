class Solution {
public:
    bool isPathCrossing(string path) {
        std::unordered_map<string, int> positions{{"0,0", 1}};
        int x{}, y{};

        for (auto& dir : path) {
            switch(dir) {
                case 'N': ++y; break;
                case 'E': ++x; break;
                case 'S': --y; break;
                case 'W': --x; break;
            }

            std::string pos = std::to_string(x) + "," + std::to_string(y);
            if (positions.find(pos) == positions.end()) {
                positions[pos] = 1;
            } else {
                return true;
            }
        }

        return false;
    }
};