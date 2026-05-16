/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) {
            return n;
        }

        while(true) {
            if (guess(n) == 0) {
                return n;
            }

            if (guess(n) == -1) {
                n /= 2;
                continue;
            }

            if (guess(n) == 1) {
                n = (n + 1) * 2;
            }
        }
    }
};