
class Solution {
public:
    //ref1: count islands, http://www.programcreek.com/2014/04/leetcode-number-of-islands-java/
    //ref2: http://www.programcreek.com/2014/04/leetcode-surrounded-regions-java/
    //ref3: https://leetcode.com/discuss/72143/efficient-java-solution-using-recursion
    //DFS, for large board, DFS causes problems, maybe stack is overflow
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
            return; //out of board
        if (board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
    }
    //https://leetcode.com/discuss/71785/imagine-the-process-of-flooding-easy-bfs-solution
    void bfs(vector<vector<char>> & board, int i, int j) {
        
        int index[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0, 1}};
        board[i][j] = '#';
        queue<pair<int, int>> q;
        q.push(make_pair(i,j));
        while (!q.empty()) {
            pair<int,int> temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            //cout << x << ' ' << y << endl;
            for (auto arr: index) {
                int newX = x + arr[0];
                int newY = y + arr[1];
                //cout << newX << ' ' << newY << endl;
                //if (newX <= 0 || newY <= 0 || newX >= board.size() - 1 || newY >= board.size()-1)
                if (newX < 0 || newY < 0 || newX > board.size() - 1 || newY > board.size()-1)
                    continue;// no need to process because they are on boarders or out of boarder
                    
                if (board[newX][newY] == 'O') {
                    board[newX][newY] = '#';
                    q.push(make_pair(newX, newY));
                }
            }
            //cout << endl;
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        //merge the O's on the boarders
        int m = board.size();
        int n = board[0].size();
        
        //top and bottom row
        for (int i = 0; i < n; i ++) {
            if (board[0][i] == 'O')
                bfs(board, 0, i);
            if (board[m-1][i] == 'O')
                bfs(board, m-1, i);
        }
        //left and right column
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n-1] == 'O')
                bfs(board, i, n - 1);
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
