
class Solution {
public:
    //idea: by counting 5's
    /*ref: Trailing 0s in n! = Count of 5s in prime factors of n!
     = floor(n/5) + floor(n/25) + floor(n/125) + ....
     */
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            n /= 5;
            res += n;
        }
        return res;
    }
};
