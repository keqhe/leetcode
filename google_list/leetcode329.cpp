

struct pairHash{
  template <typename T, typename S> 
  std::size_t operator() (const pair<T,S> & x) const {
      return std::hash<T>()(x.first) ^ std::hash<S>()(x.second);
  }
};
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>> & used, unordered_map<pair<int, int>, int, pairHash> & cache) {
       int m = matrix.size();
       int n = matrix[0].size();
       if (x < 0 || x >= m || y < 0 || y >= n || used[x][y])
        return 0;
       if (cache.find(make_pair(x, y)) != cache.end())
        return cache[make_pair(x, y)];
       used[x][y] = true;
       int localMax = 0;
       int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
       for (auto p : temp) {
           int x2 = x + p[0];
           int y2 = y + p[1];
           if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && !used[x2][y2] && matrix[x2][y2] > matrix[x][y]) {
               localMax = max(localMax, dfs(matrix, x2, y2, used, cache));
           }
       }
       used[x][y] = false;
       cache[make_pair(x, y)] = localMax+1;
       return localMax+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        unordered_map<pair<int, int>, int, pairHash> cache;
        int globalMax = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int localMax = dfs(matrix, i, j, used, cache);
                globalMax = max(globalMax, localMax);
            }
        }
        return globalMax;
    }
};
