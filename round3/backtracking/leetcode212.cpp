
//first think why we need Trie, why hash table can not work here?
//A: because hash table can not do prefix matching!
class TrieNode {
public:
  bool isLeaf;
  vector<struct TrieNode*> children;
  TrieNode() {
      isLeaf = false;
      children.resize(26, NULL);
  }
};

class Trie {
public:
  Trie() {
      root = new TrieNode();
  }  
  //insert
  void insert(string word) {
      class TrieNode * p = root;
      for (int i = 0; i < word.length(); i ++) {
          int index = word[i] - 'a';
          if (p && !p->children[index]) {
              p->children[index] = new TrieNode();
          }
          p = p->children[index];
      }
      p->isLeaf = true;
  }
  bool search(string word) {
      class TrieNode * p = root;
      for (int i = 0; i < word.length(); i ++) {
          int index = word[i] - 'a';
          if (!p || !p->children[index])
            return false;
          p = p->children[index];
      }
      return p->isLeaf;
  }
  //startsWith
  bool startsWith(string prefix) {
      class TrieNode *p = root;
      for (int i = 0; i < prefix.length(); i ++) {
          int index = prefix[i] - 'a';
          if (!p || !p->children[index])
            return false;
          p = p->children[index];
      }
      return true;
  }
private:
    class TrieNode * root;
};

class Solution {
public:
    //need to use unordered_set to filter out deuplciated results
    
    //void dfs(vector<vector<char>> &board, vector<string>& res, string path, class Trie & tr, int x, int y) {
    void dfs(vector<vector<char>> &board, unordered_set<string>& res, string path, class Trie & tr, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        
        //if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0')
        //    return;
        if (tr.startsWith(path) == false)
            return;
        if (tr.search(path) == true) {
            res.insert(path);
        }
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0')
            return;//think why it should be here, think about "a" and "a"
        char c = board[x][y];
        board[x][y] = '\0';
        dfs(board, res, path+c, tr, x-1, y);
        dfs(board, res, path+c, tr, x+1, y);
        dfs(board, res, path+c, tr, x, y-1);
        dfs(board, res, path+c, tr, x, y+1);
        board[x][y] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty())
            return res;
        int m = board.size();
        int n = board[0].size();
        class Trie tr;
        for (auto w : words) {
            tr.insert(w);
        }
        cout << "startsWith: " << tr.startsWith("a") << endl;
        cout << "search: " << tr.search("a") << endl;
        unordered_set<string> us;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dfs(board, us, "", tr, i, j);
            }
        }
        for (auto x : us)
            res.push_back(x);
        return res;
    }
};
