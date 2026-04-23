class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.size() == 1) {
            return asteroids;
        }

        int l{0};
        int r{1};

        while(r < asteroids.size()) {
            if (sign(asteroids[l]) == sign(asteroids[r])) {
                ++l; ++r;

                continue;
            }

            if (sign(asteroids[l]) < 0 && sign(asteroids[r]) > 0) {
                ++l; ++r;
                
                continue;
            }

            if (abs(asteroids[l]) == abs(asteroids[r])) {
                asteroids.erase(
                    asteroids.begin() + l, 
                    asteroids.begin() + r + 1
                );
            } else if (abs(asteroids[l]) > abs(asteroids[r])) {
                asteroids.erase(asteroids.begin() + r);
            } else {
                asteroids.erase(asteroids.begin() + l);
            }

            l = 0;
            r = 1;
        }

        return asteroids;
    }

    int abs(const int num) const {
        if (num >= 0) {
            return num;
        }

        return num * -1;
    }

    int sign(const int num) const {
        if (num == 0) {
            return 0;
        }

        return (num > 0) ? 1 : -1;
    }
};