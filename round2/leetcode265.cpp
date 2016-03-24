
class Solution {
public:
    //ref:https://segmentfault.com/a/1190000003903965
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int prevMin = 0;
        int prevSec = 0;
        int prevIdx = -1;
        for (int i = 0; i < costs.size(); i ++) {
            int currMin = numeric_limits<int>::max();
            int currSec = numeric_limits<int>::max();
            int currIdx = -1;
            for (int j = 0; j < costs[0].size(); j ++) {
                costs[i][j] += (j == prevIdx) ? prevSec : prevMin;
                if (costs[i][j] < currMin) {
                    currSec = currMin;
                    currMin = costs[i][j];
                    currIdx = j;
                }
                else if (costs[i][j] < currSec) {
                    currSec = costs[i][j];
                }
            }
            prevMin = currMin;
            prevSec = currSec;
            prevIdx = currIdx;
        }
        return prevMin;
    }
};
