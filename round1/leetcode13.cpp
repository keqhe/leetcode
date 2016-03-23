
class Solution {
public:
    //some examples of roman numbers
    //IV 4; VII 7, 
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        if (s.length() == 0)
            return 0;
        int result = 0;
        result += m[s[s.length() - 1]];
        for (int i = s.length() - 2; i >= 0; i --) {
            char c1 = s[i];
            char c2 = s[i+1];
            //cout << "c1 and m[c1] are: " << c1 << ' ' << m[c1] << endl;
            if (m[c1] >= m[c2])
                result += m[c1];
            else
                result -= m[c1];
        }
        
        return result;
    }
};
