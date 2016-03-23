
class Solution {
public:
    //https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems
    //https://leetcode.com/discuss/64529/clean-java-sliding-window-solution-with-map
    //idea: hash table + two points
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        int left = 0;
        int right = 0;
        int missing = t.size();
        unordered_map<char, int> m;
        for (auto x : t)
            m[x] ++;//each char appeared how many times
        int minLeft = 0;
        int minLen = s.size() + 1;
        
        for (right = 0; right < s.length(); right ++) {
            char c = s[right];
            if (m.find(c) != m.end()) {//c exists in t
                m[c] --;
                if (m[c] >= 0)
                    missing --;
            }
            while (missing == 0) {//all the chars in t have been found within s[left, right]
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                    cout << "minLeft now is: " << minLeft << endl;
                }
                char lc = s[left];
                if (m.find(lc) != m.end()) {
                    m[lc] ++;
                    if (m[lc] > 0)
                        missing ++;
                }
                left ++;
            }
        }
        cout << "minLeft is :" << minLeft << endl;
        cout << "minLen is :" << minLen << endl;
        if (minLen > s.size())
            return "";//no solution
        return s.substr(minLeft, minLen);
    }
};
