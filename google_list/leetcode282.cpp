
class Solution {
public:
    void backtracking(string num, int pos, int target, string path, long curr, long multi, vector<string> & res) {
        if (pos == num.length()) {
            if (curr == target) {
                res.push_back(path);
                return;
            }
        }
        if (pos >= num.length())
            return;
        
        for (int i = pos; i < num.length(); i ++) {
            string tmp = num.substr(pos, i-pos+1);
            if (tmp.length() > 1 && tmp.front()=='0')
                break;
            long number = stol(tmp);
            if (pos == 0) {
                backtracking(num, i+1, target, tmp, number, number, res);
            }
            else {
                backtracking(num, i+1, target, path+'+'+tmp, curr+number, number, res);
                backtracking(num, i+1, target, path+'-'+tmp, curr-number, -number, res);
                //1*2*3
                backtracking(num, i+1, target, path+'*'+tmp, curr-multi+multi*number, multi*number, res);
            }
        } 
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty())
            return res;
        backtracking(num, 0, target, "", 0, 0, res);
        return res;
    }
};
