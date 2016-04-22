
class Solution {
public:
    void backtracking(string s, int index, string path, int total, vector<string> & res) {
        if (index == s.length() && total == 4) {
            path.pop_back();//the last dot
            res.push_back(path);
            return;
        }
        if (index == s.length() || total == 4)
            return;
        for (int len = 1; len <= 3; len ++) {
            if (index + len > s.length())
                break;
            string str = s.substr(index, len);
            if (stoi(str) > 255)
                continue;
            if (str.front()=='0' && str.length() > 1)
                continue;
            backtracking(s, index+len, path+str+".", total+1, res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty() || s.length()>3*4 || s.length() < 4)
            return res;
        backtracking(s, 0, "", 0, res);
        return res;
    }
};
