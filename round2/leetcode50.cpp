
class Solution {
public:
    //ref: https://leetcode.com/discuss/52800/5-different-choices-when-talk-with-interviewers
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        if (n % 2 == 0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x*x, n/2);
    }
};
