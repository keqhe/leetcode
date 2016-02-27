#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || s.size() == 1 || numRows == 1)
            return s;
        vector<string> str_arr(numRows, "");
        int row = 0;
        bool downwards = true;
        for (int i = 0; i < s.length(); i ++) {
            //cout << "debug " << i << endl;
            //cout << row << " " << downwards << endl << endl;
            str_arr[row].push_back(s[i]);
            if (downwards) {
                if (row < numRows-1) {
                    row ++;
                }
                else if (row == numRows-1) {
                    row --;
                    downwards = false;
                }
            }
            else {
                if (row > 0) {
                    row --;
                }
                else if (row == 0) {
                    row ++;
                    downwards = true;
                }
            }
        }
        string res;
        for (auto x : str_arr)
            res += x;
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
