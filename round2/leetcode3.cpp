
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, 0);
        int begin = 0;
        int end = 0;
        int counter = 0;//how many chars are extra (non distinct)
        int maxLen = numeric_limits<int>::min();
        while (end < s.length()) {
            if (m[s[end]] > 0) {
                //cout << s[end] << " has more than 1 char and current end is: " << end << endl;
                counter ++;//1 more char is duplicated
            }
            m[s[end]] ++;
            end ++;
            while (counter > 0) {
                //cout << "begin:" << begin << endl;
                if (m[s[begin]] > 1) {
                    counter --;
                    //m[s[begin]] --; //WRONG, think why, think about ""tmmzuxt""
                }
                m[s[begin]] --;
                begin ++;
            }
            maxLen = max(maxLen, end-begin);
        }
        return maxLen == numeric_limits<int>::min() ? 0 : maxLen;
    }
};
