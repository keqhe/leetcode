#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    //dp[i][j] = max(1, min(dp[i+1][j],dp[i][j+1]-dungeon[i][j]), bottom-up to top-left
    //dp[i][j] denote the minimal point at position[i][j] that enables us to reach destination
    //here destination mean bottom right 
    
    //ref: https://leetcode.com/discuss/67679/java-dp-solution-3ms (2D)
    //ref: https://leetcode.com/discuss/62763/a-12-ms-c-solution-dp
    //ref: https://leetcode.com/discuss/89069/my-short-c-solution
    
    //2D
    int calculateMinimumHP_2D(vector<vector<int>>& dungeon) {
        if (dungeon.empty())
            return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = max(1, 1-dungeon[m-1][n-1]);//initialization is important
        
        //last row
        for (int j = n-2; j >=0; j --)
            dp[m-1][j] = max(1, dp[m-1][j+1]-dungeon[m-1][j]);
        //last col
        for (int i = m-2; i >= 0; i --)
            dp[i][n-1] = max(1, dp[i+1][n-1]-dungeon[i][n-1]);
        for (int i = m-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                int next = min(dp[i][j+1], dp[i+1][j]);
                dp[i][j] = max(1, next-dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
    
    
    //in the above 2D solution, dp[i][j] is only related to dp[i+1][j] and dp[i][j+1]
    //that implies that we can reduce the space complexity to 1D
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty())
            return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<int> dp(n+1, numeric_limits<int>::max());
        //dp[n-1] = max(1, 1-dungeon[m-1][n-1]);
        dp[n-1] = 1;
        
        for (int i = m-1; i >= 0; i --) {
            for (int j = n-1; j >= 0; j --) {
                int next = min(dp[j], dp[j+1]);
                dp[j] = max(1, next-dungeon[i][j]);
            }
        }
        
        return dp[0];
    }
};

int main() {
	class Solution sn;
	return 0;
}
