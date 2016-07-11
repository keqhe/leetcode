
class Solution {
public:
    //first, need to know we need to computer half 
    //second, what if n is < 0, what if n is numeric_limits<int>::min()?
    double helper(double x, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0) {
            double half = myPow(x, n/2);
            return half*half;
        }
        else {
            double half = myPow(x, n/2);
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / helper(x, abs((long)n));
        }
        else 
            return helper(x, (long)n);
    }
};
