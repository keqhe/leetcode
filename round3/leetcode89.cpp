
class Solution {
public:
    void backtracking(bitset<32>&bits, vector<int> & res, int k) {
        if (k == 0) {
            res.push_back(bits.to_ulong());
            return;
        }
        backtracking(bits, res, k-1);
        bits.flip(k-1);//only 1 bit is different
        backtracking(bits, res, k-1);
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        bitset<32> bits;
        backtracking(bits, res, n);
        return res;
    }
};
