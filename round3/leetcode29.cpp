
class Solution {
public:
    //any number can be represented by 2^n + 2^(n-1) + ... 2^0
    //9 = 2^4 + 2^0
    //idea: using shifts instead of division
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            if (dividend >= 0)
                return numeric_limits<int>::max();
            else
                return numeric_limits<int>::min();
        }
        if (divisor == 1)
            return dividend;
        if (dividend == numeric_limits<int>::min()) {
            if (divisor == -1)
                return numeric_limits<int>::max();
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;//very concise
        long long al = abs((long long)dividend);
        long long bl = abs((long long)divisor);
        cout << al << " " << bl << endl;
        long res = 0;
        
        //method 1
        while (al >= bl) {
            int multi = 0;
            
            while (al >= (bl << multi)) {
                multi ++;
            }
            al -= (bl << (multi-1));
            res += (1 << (multi-1));
        }
        //method 2
        /*
        while (al >= bl) {
            long long multi = 1;
            long long tmp = bl;
            while (al >= (tmp << 1)) {
                tmp <<= 1;
                multi <<= 1;
            }
            al -= tmp;
            res += multi;
        }*/
        cout << res << endl;
        if (sign*res > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        if (sign*res < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        return sign == 1 ? res : -res;
    }
};
