
class Solution {
public:
    //the role of multi
    void helper(string num, int pos, int target, long curr, long multi, string path, vector<string> & res) {
        if (pos == num.length()) {
            if (curr == (long)target) {
                cout << curr << " " << target << endl;
                res.push_back(path);
            }
            return;
        }
        if (pos > num.length())
            return;
        for (int i = pos; i < num.length(); i ++) {
            string tmp = num.substr(pos, i-pos+1);
            if (tmp.length()>1 && tmp.front() == '0')
                break;//no longer a valid number, for example "00" or "0123"
            long t = stol(tmp);
            if (pos == 0) {
                helper(num, i+1, target, t, t, tmp, res);
            }
            else {
                //think about "1+2*3" "1-2*3" "1+2*3*4"
                helper(num, i+1, target, curr+t, t, path+"+"+tmp, res);
                helper(num, i+1, target, curr-t, -t, path+"-"+tmp, res);
                helper(num, i+1, target, curr-multi+multi*t, multi*t, path+"*"+tmp, res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty())
            return res;
        helper(num, 0, target, 0, 0, "", res);
        return res;
    }
};
