
class Solution {
public:
    //dfs, run time error for a very large test case, so i think stack overflows
    /*
    void dfs(vector<vector<char>> & board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] == 'O') {
            board[i][j] = 'A';
            dfs(board, i-1, j);
            dfs(board, i+1, j);
            dfs(board, i, j-1);
            dfs(board, i, j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
    */
    
    //this version still TLE....
    /*
    void bfs(vector<vector<char>> & grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            grid[x][y] = 'A';
            for (auto p : temp) {
                int x2 = x + p[0];
                int y2 = y + p[1];
                
                if (x2 >=0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2] == 'O') {
                    q.push(make_pair(x2,y2));
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n-1] == 'O')
                bfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m-1][j] == 'O')
                bfs(board, m-1, j);
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
    */
    //a good ref: https://leetcode.com/discuss/88787/bfs-based-solution-in-java
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        
        
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
            }
            if (board[i][n-1] == 'O') {
                q.push(make_pair(i, n-1));
            }
        }
        
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O') {
                q.push(make_pair(0, j));
            }
            if (board[m-1][j] == 'O') {
                q.push(make_pair(m-1, j));
            }
        }
        
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            board[x][y] = 'A';
            for (auto p : temp) {
                int x2 = x + p[0];
                int y2 = y + p[1];
                
                if (x2 >=0 && x2 < m && y2 >= 0 && y2 < n && board[x2][y2] == 'O') {
                    q.push(make_pair(x2,y2));
                }
            }
        }
        
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};
