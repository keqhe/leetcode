#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //grow row by row, check colomn and diag, is the board still valid?
    bool isValid (vector<int> & usedCol, int i, int j) {
        for (int k = 0; k < usedCol.size(); k ++) {//usedCol means where col row "k" takes
            if (usedCol[k] == j || (i-k) == abs(j - usedCol[k])) 
                return false;
        }
        return true;
    }
    void backtracking(int size, int & cur_total, int cur_row, vector<int> & usedCol) {
        if (cur_row == size) {
            cur_total += 1;
        }
        
        for (int j = 0; j < size; j ++) {
            if (isValid(usedCol, cur_row, j)) {
                usedCol.push_back(j);
                backtracking(size, cur_total, cur_row+1, usedCol);
                usedCol.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int total = 0;
        vector<int> usedCol;//e.g., usedCol[0] means which column row 0 takes
        backtracking(n, total, 0, usedCol);
        
        return total;
    }
};

int main() {

	int total = 0;
	class Solution sn;
	cout << sn.totalNQueens(2) << endl;
	cout << sn.totalNQueens(8) << endl;

	return 0;
}
