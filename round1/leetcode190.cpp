
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> result (32, 0);
        uint32_t r = 0;
        int it = 0;
        while(n > 0) {
            int bit = n % 2;
            result[it] = bit;
            it ++;
            n = n / 2;
        }
        for (int i = 0; i < result.size(); i ++) {
            r += (1 << (result.size() - 1 - i)) * result[i];
        }
        return r;
    }
};
