
class Solution {
public:
    //this is recursion, but TLE, think why?
    double helper(double x, int n) {
        if (n == 1)
            return x;
        if (n == 2)
            return x*x;
        if (n % 2 == 0)
            return helper(x, n/2)*helper(x, n/2);
        else
            return x*helper(x, n/2)*helper(x, n/2);
    }
    //this about this case "x = 2 and n = -2147483648"
    double myPow_long(double x, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        if (n % 2 == 0)
            return myPow_long(x*x, n/2);
        else
            return x*myPow_long(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        return myPow_long(x, (long)n);
    }
};
