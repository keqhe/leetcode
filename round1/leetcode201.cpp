
class Solution {
public:
    //IDEA: 101 & 110 & 111 = 100, the left common part & smallest number
    int rangeBitwiseAnd(int m, int n) {
        int mask = numeric_limits<int>::max();
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return mask & m;
    }
};
