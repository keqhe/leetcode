
class Solution {
public:
    //reference 1: http://bangbingsyb.blogspot.com/2014/11/divide-two-integers-divide-two-integers.html
    //any number can be represented as a0*2^0 + a1*2^1 + a2*2^2....
    //reference 2: http://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            if (dividend >= 0)
                return numeric_limits<int>::max();
            else
                return numeric_limits<int>::min();
        }
        
        if (divisor == -1 && dividend == numeric_limits<int>::min()) {//2147483647 vs -2147483648
            return numeric_limits<int>::max(); // INT_MIN / -1 > INT_MAX; overflow
        }
        
        long pDividend = abs((long)dividend);//error prone...
        long pDivisor = abs((long)divisor);//error prone...
        
        int res = 0;
        while (pDividend >= pDivisor) {
            int lshift = 0;
            while (pDividend >= (pDivisor << lshift)) 
                lshift ++;
                
            cout << lshift << endl;
            res += 1 << (lshift - 1);
            pDividend -= pDivisor << (lshift - 1);
        }
        
        if ( (dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return res;
        else 
            return -res;
    }
};
