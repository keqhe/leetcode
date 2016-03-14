class Solution {
public:
    //0101 
    //0110
    //0111
    //see ref: https://leetcode.com/discuss/67187/java-python-easy-solution-with-explanation
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        for (; m != n; i ++) {
            m >>= 1;
            n >>= 1;
        }
        //means lower i bits are not the same
        //return ((m >> i) << i);//WRONG, note that m is alreay right shifted to the correct position
        return m << i;
    }
};
