
class Solution {
public:
    //ref: https://leetcode.com/discuss/58614/java-standard-backtrace-ac-solutoin-short-and-clear
    //ref: https://leetcode.com/discuss/83759/java-ac-solution-19ms-beat-100-00%25
    //ref: https://leetcode.com/discuss/75308/java-simple-solution-beats-96-56%25
    void dfs(string num, int pos, vector<string> & res, string path, long curr, long multi, int target) {
        if (pos == num.length()) {
            if (curr == target) {
                res.push_back(path);
            }
            return;
        }
        if (pos > num.length())
            return;
        for (int i = pos; i < num.length(); i ++) {
            if (i != pos && num[pos] == '0') //invalid number
                break;
            string tmp = num.substr(pos, i-pos+1);
            if (pos == 0) {
                dfs(num, i+1, res, path+tmp, stol(tmp), stol(tmp), target);
            }
            else {
                dfs(num, i+1, res, path+"+"+tmp, curr+stol(tmp), stol(tmp), target);
                dfs(num, i+1, res, path+"-"+tmp, curr-stol(tmp), -stol(tmp), target);
                dfs(num, i+1, res, path+"*"+tmp, curr-multi+multi*stol(tmp), multi*stol(tmp), target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty())
            return res;
        dfs(num, 0, res, "", 0, 0, target);
        return res;
    }
};
