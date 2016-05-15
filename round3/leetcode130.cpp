
class Solution {
public:
    //bfs or dfs
    //dfs causes stack overflow? (too deep)
    void dfs(vector<vector<char>>&board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0' || board[x][y] == 'X')
            return;
        board[x][y] = '\0';//means visited
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }
    //dfs meets TLE
    void solve_dfs(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                dfs(board, i, n-1);
            }
        }
        
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[m-1][j] == 'O') {
                dfs(board, m-1, j);
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '\0')
                    board[i][j] = 'O';
            }
        }
    }
    void bfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int tmp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X' || board[x][y] == '\0')
            return;
        queue<pair<int,int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            board[x][y] = '\0';
            for (auto t : tmp) {
                int x2 = x + t[0];
                int y2 = y + t[1];
                
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && board[x2][y2]  == 'O') {
                    q.push(make_pair(x2, y2));
                }
            }
        }
    }
    //the following still TLE
    void solve_bfs1(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                bfs(board, i, n-1);
            }
        }
        
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j);
            }
            if (board[m-1][j] == 'O') {
                bfs(board, m-1, j);
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '\0')
                    board[i][j] = 'O';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        int tmp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
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
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            board[x][y] = '\0';
            for (auto t : tmp) {
                int x2 = x + t[0];
                int y2 = y + t[1];
                
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && board[x2][y2]  == 'O') {
                    q.push(make_pair(x2, y2));
                }
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '\0')
                    board[i][j] = 'O';
            }
        }
    }
};
