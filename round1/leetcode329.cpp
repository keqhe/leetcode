
class Solution {
public:
    //do DFS on each cell
    //ref: https://leetcode.com/discuss/81389/15ms-concise-java-solution
    
    int tmp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    //unordered_map<pair<int,int>, int> ht;//no hash defined for pair.... WRONG!!!!
    unordered_map<string, int> ht;
    int dfs(vector<vector<int>> & matrix, int m, int n) {
        string key = to_string(m) + "-" + to_string(n);
        if (ht.find(key) != ht.end())
            return ht[key];
                      
        int Max = 1;      
        for (int i = 0; i < 4; i ++) {
                int x = m + tmp[i][0];
                int y = n + tmp[i][1];
                if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) {
                    if (matrix[x][y] > matrix[m][n]) {
                        int len =  1 + dfs(matrix, x, y);
                        Max = max(Max, len);
                    }
                }
        }
        
        ht[key] = Max;//local maximal, Max = 1;
        return Max;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int Max = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                int curr = dfs(matrix, i, j);
                Max = max(Max, curr);
            }
        }
        return Max;
    }
    //the following version gets TLE because there are redudant calculations, the idea is to use cache to avoid duplicated traversal
    /*
    void dfs(vector<vector<int>> & matrix, int m, int n, int currStep, int &maxStep) {
        if (m < 0 || n < 0 || m > matrix.size() || n > matrix[0].size())
            return;
        currStep ++;
        if (currStep > maxStep)
            maxStep = currStep;
                            
        for (int i = 0; i < 4; i ++) {
                int x = m + tmp[i][0];
                int y = n + tmp[i][1];
                if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) {
                    if (matrix[x][y] > matrix[m][n]) {
                        dfs(matrix, x, y, currStep, maxStep);
                    }
                }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int Max = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                dfs(matrix, i, j, 0, Max);
                //cout << "(" << i << "," << j << ") " << Max << endl;
            }
        }
        return Max;
    }
    */
};
