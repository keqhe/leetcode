
class Solution {
public:
    vector<string> helper(int curr, int n) {
        if (curr == 0)
            return {""};//return {""} not {}, error-prone
        if (curr == 1)
            return {"0","1","8"};
        vector<string> leftover = helper(curr-2, n);
        vector<string> res;
        for (auto s : leftover) {
            if (curr == n) {
                res.push_back("1"+s+"1");
                res.push_back("8"+s+"8");
                res.push_back("6"+s+"9");
                res.push_back("9"+s+"6");
            }
            else {
                res.push_back("0"+s+"0");
                res.push_back("1"+s+"1");
                res.push_back("8"+s+"8");
                res.push_back("6"+s+"9");
                res.push_back("9"+s+"6");
            }
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};
