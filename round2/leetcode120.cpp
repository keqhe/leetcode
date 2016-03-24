
class Solution {
public:
    //method 1 has O(n^2) space
    int minimumTotal_method1(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        for (int i = 0; i < m; i ++)
            dp[m-1][i] = triangle[m-1][i];
            
        for (int i = m-2; i >= 0; i --) {
            cout << "debug" << endl;
            for (int j = 0; j <= i; j ++) {
                
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        int m = triangle.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i ++)
            dp[i] = triangle[m-1][i];
         for (int i = m-2; i >= 0; i --) {
            cout << "debug" << endl;
            for (int j = 0; j <= i; j ++) {
                
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
