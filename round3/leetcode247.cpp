
class Solution {
public:
    vector<string> helper(int n, int top) {
        vector<string> res;
        if (n < 1)
            return res;
        if (n == 1) {
            res.push_back("0");res.push_back("1");res.push_back("8");
            return res;
        }
        if (n == 2) {
            res.push_back("11");res.push_back("88");res.push_back("69");res.push_back("96");
            if (n != top)
                res.push_back("00");
            return res;
        }
        vector<string> a = helper(n-2, top);
        
        for (auto x : a) {
            string tmp1 = "1" + x + "1";
            string tmp2 = "8" + x + "8";
            string tmp3 = "6" + x + "9";
            string tmp4 = "9" + x + "6";
            string tmp5 = "0" + x + "0";
            res.push_back(tmp1);
            res.push_back(tmp2);
            res.push_back(tmp3);
            res.push_back(tmp4);
            if (n != top) {
                res.push_back(tmp5);
            }
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};
