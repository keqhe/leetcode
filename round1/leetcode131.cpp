
class Solution {
public:
    void helper(string & s, int left, vector<vector<bool>> &isPalindrome, vector<string> & inst, vector<vector<string>> & res) {
        if (left == s.length()) {
            res.push_back(inst);
            return;
        }
        
        for (int i = left; i < s.length(); i ++) {
            if (!isPalindrome[left][i])
                continue;
            int l = i - left + 1;
            string str = s.substr(left, l);
            inst.push_back(str);
            helper(s, i+1, isPalindrome, inst, res);
            inst.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<string>> res;
        vector<string> inst;
        if (len == 0)
            return res;
        vector<vector<bool>> isPalindrome(len, vector<bool> (len, false));
        //isPalindrome[i, j] denotes whether s[i:j] is palindrome or not, same idea of Longest Palindrome Substring problem
        //if s[i+1:j-1] is palindrome and s[i] == s[j], then isPalindrome[i, j] = true
        for (int i = len - 1; i >= 0; i --) {
            for (int j = i; j < len; j ++) {
                if (i == j)
                    isPalindrome[i][j] = true;
                else if (j == i + 1 && s[i] == s[j])
                    isPalindrome[i][j] = true;
                else if (isPalindrome[i+1][j-1] && s[i] == s[j])
                    isPalindrome[i][j] = true;
                /*
                if ((i+1 >= j-1 || isPalindrome[i+1][j-1]) && s[i] == s[j])
                    isPalindrome[i][j] = true;
                */
            }
        }
            helper(s, 0, isPalindrome, inst, res);
            
            return res;
    }
};
