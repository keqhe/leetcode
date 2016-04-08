
class Solution {
public:
/*  [
    [2],
    [3,4],
    [6,5,7]
    [4,1,8,3]
    ]
*/
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        cout << m << " " << n << endl;
        for (int j = 0; j < n; j ++)
            dp[m-1][j] = triangle[m-1][j];
            
        for (int i = m-2; i >= 0; i --) {
            for (int j = 0; j <= i; j ++)
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j <= i; j ++)
                cout << dp[i][j] << ' ';
            cout << endl;
        }
        return dp[0][0];
    }
};
