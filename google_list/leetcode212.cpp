
struct TrieNode {
  bool isLeaf;
  vector<TrieNode*> children;
  TrieNode() {
      isLeaf = false;
      children.resize(26, nullptr);
  }
};

class Trie {
  public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string &word) {
        TrieNode * p = root;
        for (auto c : word) {
            int index = c - 'a';
            if (p && !p->children[index])
                p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isLeaf = true;
    }
    bool startsWidth(string & prefix) {
        TrieNode * p = root;
        for (auto c : prefix) {
            int index = c - 'a';
            if (p && !p->children[index])
                return false;
            p = p->children[index];
        }
        return true;
    }
    bool search(string & word) {
        TrieNode * p = root;
        for (auto c : word) {
            int index = c - 'a';
            if (p && !p->children[index])
                return false;
            p = p->children[index];
        }
        return p->isLeaf;
    }
  private:
    TrieNode * root;
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, Trie & tr, int x, int y, string path, unordered_set<string>& res) {
        int m = board.size();
        int n = board[0].size();
        
        if (tr.search(path)) {
            res.insert(path);
        }
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '\0') {
            if (tr.startsWidth(path)) {
                char c = board[x][y];
                board[x][y] = '\0';
                dfs(board, tr, x-1, y, path+c, res);
                dfs(board, tr, x+1, y, path+c, res);
                dfs(board, tr, x, y-1, path+c, res);
                dfs(board, tr, x, y+1, path+c, res);
                board[x][y] = c;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if (board.empty() || board[0].empty() || words.empty())
            return {};
        int m = board.size();
        int n = board[0].size();
        Trie tr;
        for (auto word : words) {
            tr.insert(word);
        }
        
        unordered_set<string> us;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dfs(board, tr, i, j, "", us);
            }
        }
        
        vector<string> res(us.begin(), us.end());
        return res;
    }
};
