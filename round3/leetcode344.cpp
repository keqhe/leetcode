
class Solution {
public:
    string reverseString(string s) {
        if (s.empty())
            return "";
        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i ++;
            j --;
        }
        return s;
    }
};
