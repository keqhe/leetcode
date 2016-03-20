
class Solution {
public:
    //TLE
    int countDigitOne_TLE(int n) {
        int count = 0;
        for (int i = 1; i <= n; i ++) {
            string s = to_string(i);
            for (auto & c : s) {
                if (c == '1') {
                    count ++;
                }
            }
        }
        return count;
    }
    //ref: https://leetcode.com/discuss/85529/very-easy-to-understand-java-solution-0ms-%E9%99%84%E4%B8%AD%E6%96%87%E8%A7%A3%E9%87%8A
    //ref: https://leetcode.com/discuss/64962/java-python-one-pass-solution-easy-to-understand
    int countDigitOne(int n) {
        int q = n;
        int mod = 1;
        int res = 0;
        do {
            int d = q % 10;
            q /= 10;
            if (d > 1)
                res += q*mod + mod;
            else if (d == 1)
                res += q*mod + n%mod + 1;
            else
                res += q*mod;
            mod *= 10;
        } while (q > 0);
        return res;
    }
};
