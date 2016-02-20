#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //my own code, TLE
    /* the first version of backtracking funciton
    bool backtracking(vector<vector<char>> & board, string word, vector<vector<bool>> & used, string path, int x, int y) {
        int mat[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (path == word) {
            cout << "found..." << endl;
            return true;
        }
        else if (path.length() == word.length())
            return false;
            
        else if (path.length() < word.length()) {
            for (int i = 0; i < path.length(); i ++) {
                if (path[i] != word[i])
                    return false;
            }
            for (auto t: mat) {
                int u = x + t[0];
                int v = y + t[1];
                
                if (u >= 0 && u < board.size() && v >= 0 && v < board[0].size() && !used[u][v]) {
                    used[u][v] = true;
                    backtracking(board, word, used, path+board[u][v], u, v);
                    used[u][v] = false;
                }
            }
        }
        else {
            return false;
        }
    }*/
    //I do not understand why mine is TLE 
    bool backtracking(vector<vector<char>> & board, string word, vector<vector<bool>> & used, string path, int x, int y) {
        int mat[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (path == word) {
            cout << "found..." << endl;
            return true;
        }
        if (path.length() < word.length()) {
            for (int i = 0; i < path.length(); i ++) {
                if (path[i] != word[i])
                    return false;
            }
            bool res = false;
            for (auto t: mat) {
                int u = x + t[0];
                int v = y + t[1];
                
                if (u >= 0 && u < board.size() && v >= 0 && v < board[0].size() && !used[u][v]) {
                    used[u][v] = true;
                    res |= backtracking(board, word, used, path+board[u][v], u, v);
                    used[u][v] = false;
                }
            }
            if (res)
                return true;
        }
        return false;
    }
    bool exist_mine(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        if (word.empty()) {
            cout << "debug..." << endl;
            return true;
        }
       
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
                    used[i][j] = true;
                    if (backtracking(board, word, used, string(1, board[i][j]), i, j))
                        return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
    
    //ref: https://leetcode.com/discuss/79246/c-solution-using-backtracking
    bool bkt(vector<vector<char>>& board, string word, int i, int j) {
        if (word.empty())
            return true;
        //the order of 1st if and 2nd if matters
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (word[0] == board[i][j]) {
            char c = word[0];
            board[i][j] = '\0';
            if (bkt(board, word.substr(1), i + 1, j) ||
                bkt(board, word.substr(1), i - 1, j) ||
                bkt(board, word.substr(1), i, j+1)   ||
                bkt(board, word.substr(1), i, j-1))
                return true;
            board[i][j] = c;
        }
        //else return false; //this is WRONG
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        if (word.empty()) {
            cout << "debug..." << endl;
            return true;
        }
       
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0]) {
                    if (bkt(board, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
	class Solution sn;
	vector<vector<char>> test;
	vector<char> tmp = {'A','B','C','E'};
	test.push_back(tmp);
	
	tmp = {'S','F','C','S'};
	test.push_back(tmp);
	
	tmp = {'A','D','E','E'};
	test.push_back(tmp);

	for (auto x : test) {
		for (auto y : x)
			cout << y;
		cout << endl;
	}
	vector<vector<char>> copy = test;//copy test
		
	cout << sn.exist(test, "ABCCED") << endl;
	test = copy;
	cout << sn.exist(test, "SEE") << endl;	
	test = copy;
	cout << sn.exist(test, "ABCB") << endl;
	test = copy;
	cout << sn.exist(test, "BFD") << endl;
	
	test = copy;
	cout << sn.exist_mine(test, "ABCCED") << endl;
	test = copy;
        cout << sn.exist_mine(test, "SEE") << endl;
	test = copy;
        cout << sn.exist_mine(test, "ABCB") << endl;
	test = copy;
	cout << sn.exist_mine(test, "BFD") << endl;
	return 0;
}
