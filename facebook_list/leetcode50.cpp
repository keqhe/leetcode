
class Solution {
public:
    double helper(double x, long n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n < 0)
            return 1.0/helper(x, abs(n));
        if (n % 2 == 0)
            return helper(x*x, n/2);
        else
            return helper(x*x, n/2)*x;
    }
    double myPow(double x, int n) {
        return helper(x, static_cast<long>(n));
    }
};
