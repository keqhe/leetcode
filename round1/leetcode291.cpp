
class Solution {
public:
    //ref1: https://leetcode.com/discuss/63388/c-backtracking
    //ref2: https://leetcode.com/discuss/63393/20-lines-java-clean-solution-easy-to-understand
     
    bool helper(string pattern, string str, int m, int n, unordered_map<char, string> &ht, unordered_set<string> &se) {
        if (m == pattern.size() && n == str.size())
            return true;
        if (ht.find(pattern[m]) != ht.end()) {
            string tmp = ht[pattern[m]];
            //str = "abcd" and n = 2 and tmp = "cde"
            if (n + tmp.length() > str.size() || tmp != str.substr(n, tmp.length()))
                return false;
            else
                return helper(pattern, str, m+1, n+tmp.length(), ht, se);
        }
        //no mapping yet
        else {
            for (int len = 1; len <= str.size() - n; len ++) {
                string tmp = str.substr(n, len);
                if (se.find(tmp) == se.end()) {//this string should not be used before
                    se.insert(tmp);
                    ht[pattern[m]] = tmp;
                    if (helper(pattern, str, m+1, n+tmp.length(), ht, se))
                        return true;
                    se.erase(tmp);
                    ht.erase(pattern[m]);
                }
            }
        }
    }
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() && str.empty())
            return true;
        if (pattern.empty() || str.empty() || pattern.length() > str.length())
            return false;
        unordered_map<char, string> ht;
        unordered_set<string> se;//for cases like p=ab and s=aa, this is not bijection anymore
        return helper(pattern, str, 0, 0, ht, se);
    }
};
