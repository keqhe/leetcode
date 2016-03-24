
class Solution {
public:
    //about math, see ref: https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return numeric_limits<int>::max();
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend == numeric_limits<int>::min())
                return numeric_limits<int>::max();
            else
                return -dividend;
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long d1 = abs((long long) dividend);
        long long d2 = abs((long long) divisor);
        
        int res = 0;
        while (d1 >= d2) {
            long long temp = d2;
            int multiple = 1;
            while (d1 >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            //cout << multiple << endl;
            d1 -= temp;
            res += multiple;
        }
        
        return sign == 1 ? res: -res;
        
    }
};
