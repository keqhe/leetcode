
class Solution {
public:
    //idea, using stack, remeber sign, 
    //ref: https://leetcode.com/discuss/71755/c-stack-solution
    int calculate(string s) {
        if (s.empty())
            return 0;
        int num = 0;
        stack<int> st;
        char sign = '+';
        for (int i = 0; i < s.length(); i ++) {
            if (isdigit(s[i]))
                num = num*10 + s[i] - '0';
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.length() - 1) {
                if (sign == '+')
                    st.push(num);
                else if (sign == '-')
                    st.push(-num);
                else if (sign == '*') {
                    int a = st.top();
                    st.pop();
                    st.push(num*a);
                }
                else if (sign == '/') {
                    int a = st.top();
                    st.pop();
                    st.push(a/num);
                }
                sign = s[i];
                num = 0;
            }
        }
        
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
