#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> & matrix, int row, int col, unordered_map<int, int> &dict) {
        int m = matrix.size();
        int n = matrix[0].size();
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int pos = row*n + col;
        if (dict.find(pos) != dict.end()) 
            return dict[pos];
        int maxDepth = 0;//note here it is 0 not 1, think why
        for (auto p : temp) {
            int x = row + p[0];
            int y = col + p[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[row][col] < matrix[x][y]) {
                int res = dfs(matrix, x, y, dict);
                maxDepth = max(maxDepth, res);
            }
        }
        dict[pos] = 1 + maxDepth;
        return 1 + maxDepth;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, int> dict;
        int maxLen = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int tmp = dfs(matrix, i, j, dict);
                maxLen = max(maxLen, tmp);
            }
        }
        return maxLen;
    }
};

int main() {
	class Solution sn;
	return 0;
}
