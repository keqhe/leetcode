
class Solution {
public:
    //the problem is to find the max len palindrome substring starting from index 0
    //a naive solution exists
    //aacecaaa
    //aaacecaa
    //aacecaaa#aaacecaa
    
    //abcd
    //dcba
    //abcd#dcba
    string shortestPalindrome(string s) {
        if (s.empty())
            return "";
        if (s.length() == 1)
            return s;
        string r = s;
        reverse(r.begin(), r.end());
        string str = s + "#" + r;
        int len = str.length();
        vector<int> KMPNext(len, 0);
        for (int i = 1, matched_pos = 0; i < len;) {
            if (str[i] != str[matched_pos]) {
                if (matched_pos > 0)
                    matched_pos = KMPNext[matched_pos-1];
                else 
                    i ++;
            }
            else {
                KMPNext[i] = matched_pos + 1;
                matched_pos ++;
                i ++;
            }
        }
        int longest_substr_len = KMPNext[len-1];
        string tmp = s.substr(longest_substr_len);
        reverse(tmp.begin(), tmp.end());
        return tmp+s;
    }
};
