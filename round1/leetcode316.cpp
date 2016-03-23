
class Solution {
public:
    //https://leetcode.com/discuss/73824/short-16ms-solution-using-stack-which-can-optimized-down-4ms
    //key idea: 
    /*
    the core idea is to keep the stack. and the stack is used to keep the current minimal char. if the next char is less than the top of stack ,then the top should be poped unless the top can not be poped. when can't we pop the top of stack ? the char is the last time to be seen in the raw string, then we can't pop it.(that's the power of cnts which can be implemented in vector~ less time maybe.)
    */
    
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;//count the number of times each char appeared in s
        string res;
        stack<char> st;
        vector<bool> visited (256, false);
        
        for (int i = 0; i < s.length(); i ++) {
            cnts[s[i]] ++;
        }
        
        for (int i = 0; i < s.length(); i ++) {
            cnts[s[i]] --;
            if (visited[s[i]]) continue;
            while (!st.empty() && st.top() > s[i] && cnts[st.top()] > 0) {
                visited[st.top()] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]] = true;
        }
        
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
