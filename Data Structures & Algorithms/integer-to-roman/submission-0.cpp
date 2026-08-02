class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, string>> table{
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" },
        };

        string result{};
        for (auto& [val, roman] : table) {
            int count = num / val;
            if (count > 0) {
                while (count > 0) {
                    result += roman;
                    --count;
                }
                num = num % val;
            }
        }

        return result;
    }
};