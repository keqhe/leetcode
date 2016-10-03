
struct pairhash {
    template<class A, class B> 
    std::size_t operator()(const pair<A, B>& p) const {
        return std::hash<A>()(p.first) ^ std::hash<B>()(p.second);
    }
};

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, unordered_map<pair<int, int>, int, pairhash>& depth) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
            return 0;
        if (depth.find(make_pair(x, y)) != depth.end())
            return depth[make_pair(x, y)];
        
        int local_max = 1;
        if (x-1 >= 0 && x-1 < m && matrix[x][y] < matrix[x-1][y]) {
            local_max = max(local_max, 1+dfs(matrix, x-1, y, depth));
        }
        if (x+1 >= 0 && x+1 < m && matrix[x][y] < matrix[x+1][y]) {
            local_max = max(local_max, 1+dfs(matrix, x+1, y, depth));
        }
        if (y-1 >= 0 && y-1 < n && matrix[x][y] < matrix[x][y-1]) {
            local_max = max(local_max, 1+dfs(matrix, x, y-1, depth));
        }
        if (y+1 >= 0 && y+1 < n && matrix[x][y] < matrix[x][y+1]) {
            local_max = max(local_max, 1+dfs(matrix, x, y+1, depth));
        }
        depth[make_pair(x, y)] = local_max;
        return local_max;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int global_max = 0;
        unordered_map<pair<int, int>, int, pairhash> depth;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                global_max = max(global_max, dfs(matrix, i, j, depth));
            }
        }
        return global_max;
    }
};
