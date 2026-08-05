class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_consumption{ 1 };
        int max_consumption{ *std::max_element(piles.begin(), piles.end()) };
        int result{ max_consumption };

        while (min_consumption <= max_consumption) {
            int eat_per_hour{ min_consumption + ((max_consumption - min_consumption) / 2) };

            int time_to_eat{};
            for (auto& pile : piles) {
                time_to_eat += std::ceil(static_cast<double>(pile) / eat_per_hour);
            }

            if (time_to_eat > h) {
                min_consumption = eat_per_hour + 1;
            } else {
                result = eat_per_hour;
                max_consumption = eat_per_hour - 1;
            }
        }

        return result;
    }
};
