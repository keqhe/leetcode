
class Solution {
public:
    //a really noce post: https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems
    
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto c : t)
            m[c] ++;
        int begin = 0; int end = 0;//two pointer
        int counter = t.length();//how many chars we need to find
        int minLen = numeric_limits<int>::max();
        int minBegin = 0;
        while (end < s.length()) {
            //if s[i] exists in t
            if (m[s[end]] > 0) {//m[s[i]] > 0 means we need to decrease counter by 1, think why
                counter --;
            }
            m[s[end]] --;//if s[i] does not exists in t, m[s[i]] is < 0
            end ++;
            //if found a valid solution
            while (counter == 0) {
                if (end - begin < minLen) {
                    minBegin = begin;
                    minLen = end - begin;//it is end-begin, not end-begin+1, think why
                }
                //below try to move begin to right by 1 position
                m[s[begin]] ++;//if m[s[begin]] > 0, that means we still need to find one more
                if (m[s[begin]] > 0)
                    counter ++;//we still need to look for
                begin ++;
            }
        }
        return minLen == numeric_limits<int>::max() ? "" : s.substr(minBegin, minLen);
    }
};
