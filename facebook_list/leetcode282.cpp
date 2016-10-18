
class Solution {
public:
    void helper(string num, int pos, long curr, long multi, string path, vector<string>&res, int target) {
        if (pos == num.length()) {
            if (static_cast<long>(target) == curr) {
                res.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.length(); i ++) {
            string x = num.substr(pos, i-pos+1);
            if (x.length() > 1 && x.front() == '0')
                break;
            long val = stol(x);
            if (pos == 0) {
                helper(num, i+1, val, val, x, res, target);
            }
            else {
                helper(num, i+1, curr+val, val, path+"+"+x, res, target);
                helper(num, i+1, curr-val, -val, path+"-"+x, res, target);
                helper(num, i+1, curr-multi+multi*val, multi*val, path+"*"+x, res, target);
            }
        } 
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(num, 0, 0, 0, "", res, target);
        
        return res;
    }
};
