
class Solution {
public:
    //naive method: time complexity is O(32*n)
    vector<int> countBits_naive(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i ++) {
            int start = 1;
            int cnt = 0;
            for (int j = 0; j <= 31; j ++) {
                if (((start << j) & i) != 0)
                    cnt ++;
            }
            res.push_back(cnt);
        }
        return res;
    }
    /*0
      1
      10 11
      100 101 110 111
      1000 1001 1010 1011 1100 1101 1110 1111
      tmp[i]  = tmp[i/2] + (i&1)
     */
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        dp[1] = 1;
        for (int i = 1; i <= num; i ++)
            dp[i] = dp[(i >> 1)] + (i&1);
        return dp;
    }
    
};
