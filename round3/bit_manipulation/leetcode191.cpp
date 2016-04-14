
class Solution {
public:
    int hammingWeight(uint32_t n) {
        long tmp = 1;
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            if ( ((tmp << i) & n) != 0)
                res ++;
        }
        return res;
    }
};
