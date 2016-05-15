
class Solution {
public:
    //KMP next table understanding + a trick
    string shortestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        string tmp = s + "#" + rs;
        
        int len = tmp.length();
        vector<int> next(len, 0);
        for (int i = 1, matched_pos= 0; i < tmp.length(); ) {
            if (tmp[i] != tmp[matched_pos]) {
                if (matched_pos > 0)
                    matched_pos = next[matched_pos-1];
                else
                    i ++;
            } 
            else {
                next[i] = matched_pos+1;
                i ++;
                matched_pos ++;
            }
        }
        
        int palLen = next[len-1];
        cout << palLen << endl;
        string leftover = s.substr(palLen);
        cout << leftover << endl;
        reverse(leftover.begin(), leftover.end());
        return leftover + s;
    }
};
