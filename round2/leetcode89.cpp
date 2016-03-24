
class Solution {
public:
    //ref:https://leetcode.com/discuss/74543/backtracking-c-solution
    //n = 2
    void backtracking(vector<int> & res, bitset<32> & bits, int k) {
        if (k == 0)
            res.push_back(bits.to_ulong());
        else {
            backtracking(res, bits, k-1);
            bits.flip(k-1);//counted from the right most, starting from 0
            backtracking(res, bits, k-1);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        bitset<32> bits;
        
        backtracking(res, bits, n);
        return res;
    }
};
