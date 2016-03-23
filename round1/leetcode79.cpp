
class Solution {
public:
    //TIME LIMIT EXCEEDED
    bool helper1(vector<vector<char>>& board, string tillnow, vector<vector<bool>> & used, int m, int n, string & word) {
        if (tillnow.length() == word.length()) {
            if (tillnow == word)
                return true;
            else
                return false;
        }
        else if (tillnow.length() < word.length()){
            int len = tillnow.length();
            if (board[m][n] != word[len])
                    return false;
            
        }
        else {
            return false;
        }
        
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || used[m][n])
            return false;
        
        
        used[m][n] = true;
        if (helper1(board, tillnow+string(1, board[m][n]), used, m-1, n, word)) return true;
        if (helper1(board, tillnow+string(1, board[m][n]), used, m+1, n, word)) return true;
        if (helper1(board, tillnow+string(1, board[m][n]), used, m, n-1, word)) return true;
        if (helper1(board, tillnow+string(1, board[m][n]), used, m, n+1, word)) return true;
        used[m][n] = false;
        
        return false;
    }
    //ref:http://bangbingsyb.blogspot.com/2014/11/leetcode-word-search.html
    bool helper2(vector<vector<char>>& board, vector<vector<bool>> & visited, int m, int n, int index, string & word) {
        if (index == word.size())
            return true;
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || visited[m][n] || board[m][n] != word[index])
            return false;
            
        visited[m][n] = true;
        if (helper2(board, visited, m-1, n, index+1, word)) return true;
        if (helper2(board, visited, m+1, n, index+1, word)) return true;
        if (helper2(board, visited, m, n-1, index+1, word)) return true;
        if (helper2(board, visited, m, n+1, index+1, word)) return true;
        visited[m][n] = false;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> used;
        used.resize(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                string s;
                //if (helper1(board, s, used, i, j, word))
                if (helper2(board, used, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
