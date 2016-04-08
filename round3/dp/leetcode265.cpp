
class Solution {
public:
    //the following has complexity of O(nk^2), n is the number of houses, k is the number of colors
    //space complexity is O(k)
    int minCostII_method1(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int k = costs[0].size();
        vector<int> dp(k, 0);
        for (int j = 0; j < k; j ++)
            dp[j] = costs[0][j];
        for (int i = 1; i < m; i ++) {
            vector<int> tmp = dp;
            for (int j = 0; j < k; j ++) {
                int minCost = numeric_limits<int>::max();
                for (int u = 0; u < k; u ++) {
                    if (u == j)
                        continue;
                    minCost = min(minCost, tmp[u]+costs[i][j]);
                }
                dp[j] = minCost;
            }
        }
        int res = numeric_limits<int>::max();
        for (int j = 0; j < k; j ++)
            res = min(res, dp[j]);
        return res;
    }
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int k = costs[0].size();
        int minColor = -1;
        int minCost = numeric_limits<int>::max();
        int secondMinCost = numeric_limits<int>::max();
        vector<int> dp(k, 0);
        for (int j = 0; j < k; j ++) {
            if (costs[0][j] < minCost) {
                secondMinCost = minCost;
                minCost = costs[0][j];
                minColor = j;
                
            }
            else if (costs[0][j] < secondMinCost) 
                secondMinCost = costs[0][j];
        }
        for (int i = 1; i < m; i ++) {
            int prev_minColor = minColor;
            int prev_minCost = minCost;
            int prev_secondMinCost = secondMinCost;
            
            minColor = -1;
            minCost = numeric_limits<int>::max();
            secondMinCost = numeric_limits<int>::max();
            
            for (int j = 0; j < k; j ++) {
                if (prev_minColor != j) {
                    if (prev_minCost + costs[i][j] < minCost) {
                        secondMinCost = minCost;
                        minCost = prev_minCost + costs[i][j];
                        minColor = j;
                    }
                    else if (prev_minCost + costs[i][j] < secondMinCost)
                        secondMinCost = prev_minCost + costs[i][j];
                }
                else {//previous round color j leads to minimal cost
                    if (prev_secondMinCost + costs[i][j] < minCost) {
                        secondMinCost = minCost;
                        minCost = prev_secondMinCost + costs[i][j];
                        minColor = j;
                    }
                    else if (prev_secondMinCost + costs[i][j] < secondMinCost)
                        secondMinCost = prev_secondMinCost + costs[i][j];
                }
            }
        }
        return minCost;
    }
};
