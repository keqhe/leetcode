
struct Trie {
  vector<struct Trie*> children;
  bool isWord;
  Trie() {
      isWord = false;
      children = vector<struct Trie*> (26, NULL);
  }
};

class Solution {
public:
    struct Trie * root;
    Solution() {
        root = new Trie();
    }
    void dfs(vector<vector<char>> & board, int i, int j, struct Trie * root, string path, unordered_set <string> &res) {
        if (!root)
            return;
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
            return;
            
        if (board[i][j] == ' ')//visited
            return;
            
        char c = board[i][j];
        int index = c -'a';
        if (root->children[index] != NULL) {
            root = root->children[index];
            path += c;
            if (root->isWord) res.insert(path);
            board[i][j] = ' ';
            dfs(board, i+1, j, root, path, res);
            dfs(board, i, j+1, root, path, res);
            dfs(board, i-1, j, root, path, res);
            dfs(board, i, j-1, root, path, res);
            board[i][j] = c;
        }
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty())
            return res;
        for (int i = 0; i < words.size(); i ++) {
            struct Trie * curr = root;
            for (int j = 0; j < words[i].length(); j ++) {
                
                int index = words[i][j] - 'a';
                if (!curr->children[index]) {
                    curr->children[index] = new Trie();
                }
                curr = curr->children[index];
            }
            curr->isWord = true;
        } 
        
        unordered_set<string> se;
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                dfs(board, i, j, root, "", se);
            }
        }
        
        for (auto & x: se) 
            res.push_back(x);
        return res;
    }
};
