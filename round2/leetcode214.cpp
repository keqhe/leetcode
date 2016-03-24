
class Solution {
public:
    //abcde (5-1)/2
    //abcdef (6-1)/2
    
    //aacd
    //the code below faces TLE
    /*
    bool helper(int l, int r, string s) {
        if (l > r)
            return false;
        while (l >= 0 && s[l] == s[r]) {
            l --;
            r ++;
        }
        if (l == -1)
            return true;
        else
            return false;
    }
    string shortestPalindrome(string s) {
        if (s.empty())
            return "";
        int len = s.length();
        
        int l = (len-1) / 2;
        int r = (len) / 2;
        cout << l << " " << r << endl;
        while (l >= 0) {
            if (!helper(l, r, s)) {
                if (l == r) {
                    l --;
                }
                else {
                    r --;
                }
            }
            else 
                break;
        }
        cout << l << " " << r << endl;
        string tmp = s.substr(r+l+1);
        reverse(tmp.begin(), tmp.end());
        return tmp+s;
    }
    */
    //ref: https://leetcode.com/discuss/64309/clean-kmp-solution-with-super-detailed-explanation
    //this is a deep understanding of KMP, 
    string shortestPalindrome(string s) {
        if (s.empty() || s.size() == 1)
            return s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        string pattern = s + "#" + rs;
        vector<int> next(pattern.length(), 0);
        for (int i = 1, matched_pos = 0; i < pattern.length(); ) {
            if (pattern[i] == pattern[matched_pos]) {
                next[i] = matched_pos + 1;
                i ++;
                matched_pos ++;
            }
            else {
                if (matched_pos > 0) {
                    matched_pos = next[matched_pos-1];
                }
                else
                    i ++;
            }
        }
        int index = next[pattern.length()-1];
        string leftover = s.substr(index);
        reverse(leftover.begin(), leftover.end());
        return leftover + s;
    }
};
