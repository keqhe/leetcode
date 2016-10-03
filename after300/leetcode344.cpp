
class Solution {
public:
    string reverseString(string s) {
        if (s.empty())
            return "";
        int l = 0;
        int r = s.length()-1;
        while (l < r) {
            swap(s[l], s[r]);
            l ++;
            r --;
        }
        return s;
    }
};
