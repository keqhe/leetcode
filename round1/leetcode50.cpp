
class Solution {
public:
    //binary search,
    //consider the case n < 0 and n = 0;
    double helper(double x, int n) {
        if (n == 0)
            return 1.0;
        double half = helper(x, n/2);
        if (n % 2 == 0)
            return half*half;
        else
            return half*half*x;
    }
    double myPow(double x, int n) {
        if (n<0)
            return double(1.0)/helper(x, -n);
        else
            return helper(x, n);
    }
    //TIME Limit Exceeded
    double myPow_TLE(double x, int n) {
        double res = 1.0;
        for (int i = 0; i < n; i ++)
            res *= x;
        return res;
    }
};
