class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.size() < 2) {
            return asteroids;
        }

        std::vector<int> res{};

        for(auto& asteroid : asteroids) {
            while(!res.empty() && asteroid < 0 && res.back() > 0) {
                int diff = asteroid + res.back();

                if (diff < 0) {
                    res.pop_back();
                } else if (diff > 0) {
                    asteroid = 0;
                } else {
                    asteroid = 0;
                    res.pop_back();
                }
            }

            if (asteroid != 0) {
                res.push_back(asteroid);
            }
        }

        return res;
    }
};