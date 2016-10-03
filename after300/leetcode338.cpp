
class Solution {
public:
    //1000
    vector<int> countBits_naive(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i ++) {
            int cnt = 0;
            for (int j = 0; j <= 31; j ++) {
                if (((1 << j) & i) != 0)
                    cnt ++;
            }
            res.push_back(cnt);
        }
        return res;
    }
    //dp[i] = dp[(i >> 1)] + i & 1;
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; i ++)
            dp[i] = dp[(i >> 1)] + (i & 1);
        return dp;
    }
};
