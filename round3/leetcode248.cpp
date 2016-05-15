
class Solution {
public:
    bool strCmp(string s1, string s2) {
        
        if (s1.size() == s2.size())
            return s1 < s2;
        else
            return s1.size() < s2.size();
    }
    void helper(string curr, string low, string high, int & cnt) {
        
        if (strCmp(high, curr))
            return;
        if (!strCmp(high, curr) && !strCmp(curr, low)) {
            if (curr.length() == 1 || curr.length() > 1 && curr.front() != '0')
                cnt ++;
        }
            
        helper('0'+curr+'0', low, high, cnt);
        helper('1'+curr+'1', low, high, cnt);
        helper('8'+curr+'8', low, high, cnt);
        helper('6'+curr+'9', low, high, cnt);
        helper('9'+curr+'6', low, high, cnt);
    }
    int strobogrammaticInRange(string low, string high) {
        if (strCmp(high, low))
            return 0;
        int cnt = 0;
        helper("", low, high, cnt);
        helper("1", low, high, cnt);
        helper("0", low, high, cnt);
        helper("8", low, high, cnt);
        return cnt;
    }
};
