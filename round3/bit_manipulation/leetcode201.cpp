
class Solution {
public:
    //only the highest bits that are the same in m and n are left, all other bits are zeroed out
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        for (; m != n; i ++) {
            m >>= 1;
            n >>= 1;
        }
        return m << i;
    }
};
