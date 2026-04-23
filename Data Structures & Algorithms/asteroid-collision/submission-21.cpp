class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.size() < 2) {
            return asteroids;
        }

        std::vector<int> res{};

        for(auto& asteroid : asteroids) {
            if (
                res.empty() || 
                sign(res.back()) == sign(asteroid) ||
                sign(res.back()) < 0 && sign(asteroid) > 0
            ) {
                res.push_back(asteroid);
                continue;
            }

            while (sign(res.back()) > 0) {
                if (std::abs(res.back()) > std::abs(asteroid)) {
                    break;
                }

                if (std::abs(res.back()) == std::abs(asteroid)) {
                    res.pop_back();
                    break;
                }

                if (std::abs(res.back()) < std::abs(asteroid)) {
                    res.pop_back();
                    if (sign(res.back()) < 0) {
                        res.push_back(asteroid);
                    }
                } 
                else {
                    res.push_back(asteroid);
                }

                if (res.empty()) {
                    res.push_back(asteroid);
                    //break;
                }
            }
        }

        return res;
    }

    // vector<int> asteroidCollision(vector<int>& asteroids) {
    //     if (asteroids.size() == 1) {
    //         return asteroids;
    //     }

    //     int l{0};
    //     int r{1};

    //     while(r < asteroids.size()) {
    //         if (sign(asteroids[l]) == sign(asteroids[r])) {
    //             ++l; ++r;

    //             continue;
    //         }

    //         if (sign(asteroids[l]) < 0 && sign(asteroids[r]) > 0) {
    //             ++l; ++r;

    //             continue;
    //         }

    //         if (std::abs(asteroids[l]) == std::abs(asteroids[r])) {
    //             asteroids.erase(
    //                 asteroids.begin() + l, 
    //                 asteroids.begin() + r + 1
    //             );
    //         } else if (std::abs(asteroids[l]) > std::abs(asteroids[r])) {
    //             asteroids.erase(asteroids.begin() + r);
    //         } else {
    //             asteroids.erase(asteroids.begin() + l);
    //         }

    //         l = 0;
    //         r = 1;
    //     }

    //     return asteroids;
    // }

    int sign(const int num) const {
        if (num == 0) {
            return 0;
        }

        return (num > 0) ? 1 : -1;
    }
};