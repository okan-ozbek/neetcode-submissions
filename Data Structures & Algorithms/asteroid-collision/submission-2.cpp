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
                ++l;
                ++r;
                continue;
            }

            if (sign(asteroids[l]) < 0 && sign(asteroids[r]) > 0) {
                ++l;
                ++r;
                continue;
            }

            if (abs(asteroids[l]) == abs(asteroids[r])) {
                asteroids.erase(asteroids.begin() + r);
                asteroids.erase(asteroids.begin() + l);
            } else if (abs(asteroids[l]) > abs(asteroids[r])) {
                asteroids.erase(asteroids.begin() + r);
            } else {
                asteroids.erase(asteroids.begin() + l);
            }

            l = 0;
            r = 1;
        }

        return asteroids;

        // if asteroid1 sign == asteroid2 sign
            // asteroid1 + 1
            // asteroid2 + 1;

        // if asteroid1 > 0 && asteroid2 < 0
            // hit
            // if asteroid1 > asteroid2
                // remove asteroid1
            // else 
                // remove asteroid2
            
        
    }

    void print(vector<int> v) {
        for (auto& x : v) {
            std::cout << "[" << x << "]" << std::endl;
        }
    }

    int abs(int num) {
        if (num >= 0) {
            return num;
        }

        return num * -1;
    }

    int sign(int num) {
        if (num > 0) {
            return 1;
        }

        if (num < 0) {
            return -1;
        }

        return 0;
    }
};