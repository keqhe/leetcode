
class Solution {
public:
    //idea 1: left shift 
    bool isPowerOfTwo(int n) {
        
        for (int i = 0; i <= 31; i ++) {
            long b = ((long)1 << i);
            //int b = (1 << i);//think about (1 << 31)
            if (n == b)
                return true;
            else if (n < b)
                return false;
        }
    }
    //idea: if an integer is power of 2, then only 1 bit in 1
    bool isPowerOfTwo_idea2(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};
