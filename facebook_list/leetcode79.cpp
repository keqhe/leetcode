
lass Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y) {
        if (word.empty())
            return true;
        int m = board.size();
        int n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        if (board[x][y] != word.front())
            return false;
        char c = board[x][y];
        board[x][y] = '\0';
        if (dfs(board, word.substr(1), x+1, y) ||
            dfs(board, word.substr(1), x-1, y) ||
            dfs(board, word.substr(1), x, y-1) ||
            dfs(board, word.substr(1), x, y+1))
            return true;
        board[x][y] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        if (word.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (dfs(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
