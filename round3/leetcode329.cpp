
class Solution {
public:
    //needs to use memorization to reduce time complexity
    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& used, int x, int y, unordered_map<string, int> & ht) {
        string key = to_string(x) + "-" + to_string(y);
        if (ht.find(key) != ht.end())
            return ht[key];
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || used[x][y])
            return 0;
        int tmp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        used[x][y] = true;
        int localMax = 0;
        for (auto p : tmp) {
            int x2 = x + p[0];
            int y2 = y + p[1];
            if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && !used[x2][y2] && matrix[x2][y2] > matrix[x][y]) {
                localMax = max(localMax, dfs(matrix, used, x2, y2, ht));
            }
        }
        used[x][y] = false;//dfs ended
        ht[key] = localMax+1;
        return localMax+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<bool>> used(m, vector<bool>(n, false));
        unordered_map<string, int> ht;
        int maxStep = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int currMax = dfs(matrix, used, i, j, ht);
                maxStep = max(currMax, maxStep);
            }
        }
        return maxStep;
    }
};
