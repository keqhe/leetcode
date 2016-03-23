
class Solution {
public:
    //https://leetcode.com/discuss/60625/fast-dp-java-solution-runtime-o-nk-space-o-1
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int n = costs[0].size();
        
        int prevMin = 0;//min cost till last house
        int prevMinColor = -1;//to get min cost, which color last house uses?
        int prevSecMin = 0;//what the second smallest cost till last house?
        
        
        for (int i = 0; i < m; i ++) {
            int currMin = numeric_limits<int>::max();
            int currMinColor = -1;
            int currSecMin = numeric_limits<int>::max();
            for (int j = 0; j < n; j ++) {
                int val;
                if (j == prevMinColor) {
                    val = costs[i][j] + prevSecMin;
                }
                else {
                    val = costs[i][j] + prevMin;
                }
                
                if (currMinColor == -1) {
                    currMin = val;
                    currMinColor = j;
                }
                else if (val < currMin) {
                    currSecMin = currMin;
                    currMin = val;
                    currMinColor = j;
                }
                else if (val < currSecMin) //val >= currMin && val < currSecMin
                    currSecMin = val;
            }
            prevMin = currMin;
            prevMinColor = currMinColor;
            prevSecMin = currSecMin;
        }
        
        return prevMin;
    }
};
