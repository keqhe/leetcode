
class Solution {
public:
    //dfs
    bool dfs(vector<vector<char>>&board, string word, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        if (word.empty())   
            return true;
            
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        
        if (word.front() == board[x][y]) {
            char c = board[x][y];
            board[x][y] = '\0';
            if (dfs(board,word.substr(1), x-1, y) || 
                dfs(board,word.substr(1), x+1, y) ||
                dfs(board,word.substr(1), x, y-1) ||
                dfs(board,word.substr(1), x, y+1))
                return true;
            board[x][y] = c;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (word.front() == board[i][j]) {
                    if (dfs(board, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
