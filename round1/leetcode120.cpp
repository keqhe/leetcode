
class Solution {
public:
    //dynamic programming: t[i][j] = min(t[i+1][j], t[i+1][j+1]) + triangle[i][j];
    //bottom up is easier
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        int n = triangle.size();//triangle: # of rows = # of columns of last row
        vector<int> sums (n, 0);
        
        //initialize by the last row
        for (int i = 0; i < triangle[n-1].size(); i ++) {
            sums[i] = triangle[n-1][i];
        }
        
        for (int i = n-2; i >= 0; i --) {
            int len = triangle[i].size();
            for (int j = 0; j < len; j ++) {
                sums[j] = min(sums[j], sums[j+1]) + triangle[i][j];
            }
        }
        
        return sums[0];
    }
};
