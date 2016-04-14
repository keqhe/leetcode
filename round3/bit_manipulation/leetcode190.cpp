
class Solution {
public:
    //because it is unsigned int, so there is no overflow problem
    //think how decimal works, the same case for binary!
    uint32_t reverseBits(uint32_t n) {
        //the following is WRONG, think why
        /*
        int sum = 0;
        while (n > 0) {
            int digit = n % 2;
            sum = sum*2 + digit;
            n /= 2;
        }
        return sum;
        */
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            int digit = n & 1;//the same as n % 2;
            //int digit = n % 2;
            n = (n >> 1);
            res = (res<<1) + digit;
        }
        return res;
    }
};
