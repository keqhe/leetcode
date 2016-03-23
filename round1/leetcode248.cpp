
class Solution {
public:
    //ref: https://leetcode.com/discuss/55468/clear-java-ac-solution-using-strobogrammatic-number-method
    //less memeory used version, see: https://leetcode.com/discuss/61245/c-ac-and-clean-any-ideas-to-make-it-faster
    bool strCmp(string s1, string s2) {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        else
            return s1 < s2;
    }
    void helper(int & count, string temp, string &low, string &high) {
        
        if (strCmp(high, temp))
            return;
        if (!strCmp(high, temp) && !strCmp(temp, low))
            if (temp.length() == 1 || temp.length() > 1 && temp[0] != '0')
                count ++;
        helper(count, "0"+temp+"0", low, high);
        helper(count, "1"+temp+"1", low, high);
        helper(count, "8"+temp+"8", low, high);
        helper(count, "6"+temp+"9", low, high);
        helper(count, "9"+temp+"6", low, high);
    }
    
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        helper(count, "", low, high);
        helper(count, "0", low, high);
        helper(count, "1", low, high);
        helper(count, "8", low, high);
        return count;
    }
    
    /*below memory limit exceeded because string are stored first and then check the count*/
    //Strobogrammatic Number II
    /*
    vector<string> helper(int curr, int max) {
        vector<string> res;
        if (curr == 0) {
            res.push_back("");
            return res;
        }
        if (curr == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        vector<string> tmp = helper(curr-2, max);
        vector<string> prefix = {"0", "1", "8", "6", "9"};
        vector<string> suffix = {"0", "1", "8", "9", "6"};
        string a;
        for (auto & s : tmp) {
            for (int i = 0; i < prefix.size(); i ++) {
                a = prefix[i];
                a += s + suffix[i];
                if (a[0] == '0' && curr == max)
                    continue;
                res.push_back(a);
            }
        }
        return res;
    }
    int strobogrammaticInRange_mle(string low, string high) {
        vector<string> res;
        vector<string> tmp;
        for (int i = low.length(); i <= high.length(); i ++) {
            tmp.clear();
            tmp = helper(i, i);
            for (auto & x: tmp)
                res.push_back(x);
        }
        int count = 0;
        for (auto & x : res) {
            //cout << "x : " << x << endl;
            if (x.length() == low.length() && x < low || x.length() == high.length() && x > high)
                continue;
            count ++;
        }
        return count;
    }
    */
};
