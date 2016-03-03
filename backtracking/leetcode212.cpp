#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    struct TrieNode {
      bool isEnd;
      vector<struct TrieNode*> children;
      TrieNode() {
          isEnd = false;
          children.resize(26, NULL);
      }
    };
    class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(string word) {
            struct TrieNode * p = root;
            for (int i = 0; i < word.length(); i ++) {
                int index = word[i] - 'a';
                if (!p->children[index])
                    p->children[index] = new TrieNode();
                p = p->children[index];
            }
            p->isEnd = true;
        }
        pair<bool, bool> startsWith(string prefix) {
            struct TrieNode * p = root;
            for (int i = 0; i < prefix.length(); i ++) {
                int index = prefix[i] - 'a';
                if (!p->children[index]) {
                    pair<bool, bool> tmp = make_pair(false, false);
                    return tmp;
                }
                else
                    p = p->children[index];
            }
            if (p->isEnd)
                return make_pair(true, true);
            else
                return make_pair(true, false);
        }
    private:
        struct TrieNode * root;
    };
    //two points are error prone, first about used, second is about return too early (note this is WRONG, because even isEnd is reached, you need to search further)
    void backtracking(vector<vector<char>>&board, class Trie & t, int row, int col, string path, vector<vector<bool>> & used, unordered_set<string> & res) {
        int ways[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        path.push_back(board[row][col]);
        
        pair<bool, bool> check = t.startsWith(path);
        if (!check.first)
            return;
        else if (check.second) {
            res.insert(path);
            //return; //note this is WRONG, because even isEnd is reached, you need to search further
        }
        //else { //note this is WRONG,because even isEnd is reached, you need to search further
            for (auto one : ways) {
                int x = row + one[0];
                int y = col + one[1];
                if (path == "aaa") {
                    if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
                            cout << used[x][y] << endl << endl;
                }
                if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !used[x][y]) {
                    used[row][col] = true;
                    backtracking(board, t, x, y, path, used, res);
                    //reset used to false
                    used[row][col] = false;
                }
            }
        //}
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        unordered_set<string> se;
        if (board.empty() || board[0].empty())
            return res;
            
        class Trie t;
        for (auto w: words) {
            t.insert(w);
        }
        pair<bool, bool> p = t.startsWith("aaab");
        cout << p.first << " " << p.second << endl;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used (m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                backtracking(board, t, i, j, "", used, se);
            }
        }
        for (auto x : se)
            res.push_back(x);
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
