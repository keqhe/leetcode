
class Solution {
public:
    //I 1
    //II 2
    //III 3
    //IV 4
    /* I  V  X   L  C    D    M 
       1  5  10  50 100  500  1000
    */
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (i + 1 < s.length() && m[s[i]] < m[s[i+1]])
                res += 0 - m[s[i]];
            else
                res += m[s[i]];
        }
        return res;
    }
};
