// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        if (pairs.size() == 0) {
            return {};
        }

        std::vector<std::vector<Pair>> res{};

        res.push_back(pairs);

        for (std::size_t i{ 1 }; i < pairs.size(); ++i) {
            std::size_t j{ i - 1 };

            while (j >= 0 && pairs[j + 1].key < pairs[j].key) {
                std::swap(pairs[j + 1], pairs[j]);
                if (j == 0) break;

                --j;
            } 

            res.push_back(pairs);
        }

        return res;
    }
};
