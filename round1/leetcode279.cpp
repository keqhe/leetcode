
class Solution {
public:
    //dynamic programming, time complexity is O(n*sqrt(n))
    //https://leetcode.com/discuss/58056/summary-of-different-solutions-bfs-static-and-mathematics
    int numSquares_dp(int n) {
        vector<int> dp(n+1, numeric_limits<int>::max());
        for (int i = 1; i*i <= n; i ++) {
            dp[i*i] = 1;//dp[1, 4, 9, 16] = 1
        }
        //say, n = 12
        //when i = 1, dp[2] = 2, dp[5]=2, dp[10] = 2
        //when i = 2, dp[3] = 2, dp[6]=2, dp[11] = 2;
        //when i = 3, dp[4] = 1, dp[7]=3, dp[12] = 3
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; i + j*j <= n; j++) {
                dp[i+j*j] = min(dp[i+j*j], dp[i] + 1);
                //cout << "i: " << i << " j: " << j << " dp[" << i+j*j<<"]: " << dp[i+j*j] << endl;
            }
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        vector<int> ps;
        vector<int> cnt(n+1, 0);
        for (int i = 1; i*i <= n; i ++) {
            ps.push_back(i*i);
            cnt[i*i] = 1;
        }
        if (n == ps.back())
            return 1;
        queue<int> q;
        for (int i = 0; i < ps.size(); i ++) {
            q.push(ps[i]);
        }
        int curr = 1;
        
        while(!q.empty()) {
            curr ++;
            int qsize = q.size();
            for (int j = 0; j < qsize; j ++) {//level by level
                int tmp = q.front();
                q.pop();
                for (int i = 0; i < ps.size(); i ++) {
                    int now = ps[i] + tmp;
                    if (now == n)
                        return curr;
                    else if (now < n && cnt[now] == 0) {
                        cnt[now] = curr;
                        q.push(now);
                    }
                    else if (now > n)
                        break;
            }
            }
            
        }
        return 0;
    }
};
