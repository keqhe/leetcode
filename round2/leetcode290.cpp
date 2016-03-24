
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() || str.empty())
            return false;
        int space_count = 0;
        for (int i = 0; i < str.length(); i ++)
            if (isspace(str[i]))
                space_count ++;
        if ((space_count + 1) != pattern.length())
            return false;
        int i = 0;
        int j = 0;
        int k = 0;
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        while (i < pattern.length()) {
            //cout << i << " " << j << " " << k << endl;
            char c = pattern[i++];
            while (k < str.length() && str[k] != ' ')
                k ++;
            string s = str.substr(j, k-j);
            j = k + 1;
            k = j;
            
            if (m1.find(c) == m1.end())
                m1[c] = s;
            else {
                if (m1[c] != s)
                    return false;
            }
            
            if (m2.find(s) == m2.end())
                m2[s] = c;
            else {
                if (m2[s] != c)
                    return false;
            }
        }
        return true;
    }
};
