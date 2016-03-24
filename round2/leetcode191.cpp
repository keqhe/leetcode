
class Solution {
public:
    int hammingWeight(uint32_t n) {
        long tmp;
        int count = 0;
        for (int i = 0; i <= 31; i ++) {
            tmp = 1 << i;
            if (tmp & n)
                count ++;
        }
        return count;
    }
};
