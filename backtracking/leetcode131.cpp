#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            else {
                i ++;
                j --;
            }
        }
        return true;
    }
    void backtracking(string s, int index, vector<string> & path, vector<vector<string>>& res) {
        if(s.length() == index) {
            res.push_back(path);
            return;
        }
        int len = s.length() - index;
        for (int i = 1; i <= len; i ++) {
            string tmp = s.substr(index,i);
            if (isPalindrome(tmp)) {
                path.push_back(tmp);
                backtracking(s, index+i, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtracking(s, 0, path, res);
        return res;
    }
};

int main() {
	class Solution sn;	
	return 0;
}
