
class Solution {
public:
    //ref:http://www.cnblogs.com/TenosDoIt/p/3793503.html
    //m["I"] = 1, m
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        if (s.empty())
            return 0;
        int res = 0;
        int i;
        for (i = 0; i < s.length() - 1; i ++) {
            if (m[s[i]] < m[s[i+1]])
                res -= m[s[i]];
            else
                res += m[s[i]];
        }
        res += m[s[i]];
        return res;
    }
};
