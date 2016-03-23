
class Solution {
public:
    //ref: http://www.hrwhisper.me/leetcode-longest-valid-parentheses/
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        stack<int> left;
        vector<bool> match(s.length(), false);
        
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')' && !left.empty()) {
                match[left.top()] = true;
                match[i] = true;
                left.pop();
            }
        }
        
        int temp = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (match[i] == 0) {
                temp = 0;
                continue;
            }
            temp ++;
            res = max(res, temp);
        }
        
        return res;
    }
};
