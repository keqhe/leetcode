
class Solution {
public:
    //bijection mapping, 
    bool backtracking(string pattern, string str, int index1, int index2, unordered_map<char, string> &m) {
        if (index1 == pattern.length() && index2 == str.length()) {
            unordered_map<string, char> check;//bijection checking
            for (auto c : pattern) {
                if (m.find(c) == m.end())
                    return false;
                if (check.find(m[c]) != check.end() && check[m[c]] != c)//think why
                    return false;
                check[m[c]] = c;
            }
            return true;
        }
        if (index1 == pattern.length() || index2 == str.length())
            return false;
        if (m.find(pattern[index1]) != m.end()) {
            string tmp = m[pattern[index1]];
            if (tmp == str.substr(index2, tmp.length())) {//think why
                if (backtracking(pattern, str, index1+1, index2+tmp.length(), m))
                    return true;
            }
        }
        else {
            for (int i = index2; i < str.length(); i ++) {
                string tmp = str.substr(index2, i-index2+1);
                m[pattern[index1]] = tmp;
                if (backtracking(pattern, str, index1+1, index2+tmp.length(), m))
                    return true;
                m.erase(pattern[index1]);
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        if (str.length() < pattern.length())
            return false;
        unordered_map<char, string> m;
        bool res = backtracking(pattern, str, 0, 0, m);
        return res;
    }
};
