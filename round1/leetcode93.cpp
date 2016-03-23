
class Solution {
public:
    //backtracking
    //ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-restore-ip-addresses.html
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> inst;
        if (s.length() > 12)
            return res;
        back(s, inst, 0, res);
        
        return res;
    }
    
    bool isValid(string s) {
        //if (s.size() > 3) return false;//this might be required..
        if (s.size() > 0 && s[0] == '0' && s.size() != 1) return false;
        if (s.size() == 3 && stoi(s) > 255) return false;
        return true;
    }
    void back(string &s, vector<string> & inst, int start, vector<string> & res) {
        if (inst.size() == 4 && start == s.length()) {//a valid IP addresss
            string t;
            for (int i = 0; i < 4; i ++) 
                t += inst[i] + ".";
            t.pop_back();
            res.push_back(t);
            return;
        }
        
        string cur;
        for (int i = start; i < s.length() && i < start + 3; i ++) {
            cur.push_back(s[i]);
            if (isValid(cur)) {
                inst.push_back(cur);
                back(s, inst, i+1, res);
                inst.pop_back();
            }
        }
    }
};
