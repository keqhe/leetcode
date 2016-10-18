
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int k = costs[0].size();
        vector<int> dp(k, 0);
        int minColor = -1;
        int minCost = numeric_limits<int>::max();
        int secondMinCost = numeric_limits<int>::max();
        for (int j = 0; j < k; j ++) {
            if (costs[0][j] < minCost) {
                secondMinCost = minCost;
                minCost = costs[0][j];
                minColor = j;
            }
            else if (costs[0][j] < secondMinCost) {
                secondMinCost = costs[0][j];
            }
        }
        
        for (int i = 1; i < m; i ++) {
            int prev_minColor = minColor;
            int prev_minCost = minCost;
            int prev_secondMinCost = secondMinCost;
            
            minColor = -1;
            minCost = numeric_limits<int>::max();
            secondMinCost = numeric_limits<int>::max();
            for (int j = 0; j < k; j ++) {
                if (j != prev_minColor) {
                    if (costs[i][j]+prev_minCost < minCost) {
                        secondMinCost = minCost;
                        minCost = costs[i][j]+prev_minCost;
                        minColor = j;
                    }
                    else if (costs[i][j]+prev_minCost < secondMinCost) {
                        secondMinCost = costs[i][j]+prev_minCost;
                    }
                }
                else {
                    if (costs[i][j]+prev_secondMinCost < minCost) {
                        secondMinCost = minCost;
                        minCost = costs[i][j]+prev_secondMinCost;
                        minColor = j;
                    }
                    else if (costs[i][j]+prev_secondMinCost < secondMinCost) {
                        secondMinCost = costs[i][j]+prev_secondMinCost;
                    }
                }
            }
            
        }
        return minCost;
    }
};
