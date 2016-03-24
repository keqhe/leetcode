
class Solution {
public:
    void backtracking(string s, int index, int num, string path, vector<string> & res) {
        if (s.length() == index && num == 4) {
            res.push_back(path);
            return;
        }
        if (index >= s.length() || num > 4)
            return;
        for (int l = 1; l+index <= s.length(); l ++) {
            string str = s.substr(index, l);
            if (str.empty())
                continue;
            if (str.length() != 1 && str.front() == '0')
                continue;
            if (stol(str) >= 0 && stol(str) <= 255) {
                backtracking(s, index+l, num+1, path==""?str:(path+'.'+str), res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12)
            return res;//"11111111111111111111111...." test case
        backtracking(s, 0, 0, "", res);
        return res;
    }
};
