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
            int r{ guess(n) };
            
            if (r == 0) {
                return n;
            } else if (r == -1) {
                n = n / 2;
            } else {
                n = (n + 1) * 2;
            }
        }
    }
};