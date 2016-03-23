
class Solution {
public:
    //reference: http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
    //time complexity: O(n)
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int prev_index;
        unordered_map<char, int> m; //char, position (last appeared)
        int max_len = 1;
        int cur_len = 1;
        
        m[s[0]] = 0;//s[0] appeared at position 0
        
        for (int i = 1; i < s.length(); i ++) {
            int c = s[i];
            if (m.find(c) == m.end()) //never appeared
                cur_len ++;
            else {//c appeared before
                prev_index = m[c]; //c appeared at index "prev_index"
                if (i - cur_len > prev_index) {//c appeared, but not in the current substring we are checking
                    cur_len ++;
                }
                else {
                    if (cur_len > max_len)
                        max_len = cur_len;
                    cur_len = i - m[c];//e.g., "aba"
                }
            }
            m[c] = i;
        }
        if (cur_len > max_len)
            max_len = cur_len;
        return max_len;
    }
};
