
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int res = 0;
        for (int i = 0; i < 32; i ++) {
            int t = n & 1;
            cout << t << " ";
            n = n >> 1;
            res += t;
            if (i != 31)
                res = res << 1;
            cout << res << endl;
        }
        cout << endl;
        return res;
    }
};
