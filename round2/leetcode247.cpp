
class Solution {
public:
    vector<string> helper(int n, int bound) {
        vector<string> res;
        if (n == 0) {
            res.push_back("");
            return res;
        }
            
        if (n == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        
        vector<string> tmp = helper(n-2, bound);
        for (auto x : tmp) {
            string t;
            t = "1" + x + '1';
            res.push_back(t);
            t = "8" + x + '8';
            res.push_back(t);
            if (n != bound) {
                t = "0" + x + '0';
                res.push_back(t);
            }
            t = "6" + x + '9';
            res.push_back(t);
            t = "9" + x + '6';
            res.push_back(t);
        }
        
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};
