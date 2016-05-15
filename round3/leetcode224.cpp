
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        int res = 0;
        int flag = 1;
        stack<int> st;
        for (int i = 0; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                int curr = s[i] - '0';
                while (i+1 < s.length() && isdigit(s[i+1])) {
                    curr = curr*10 + s[i+1] - '0';
                    i ++;
                }
                res += curr*flag;
            }
            else if (s[i] == '+')
                flag = 1;
            else if (s[i] == '-')
                flag = -1;
            else if (s[i] == '(') {
                st.push(res);
                st.push(flag);
                res = 0;
                flag = 1;
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    int a = st.top();//sign
                    st.pop();
                    int b = st.top();//the number before sign
                    st.pop();
                    res = res*a + b;
                }
            }
        }
        return res;
    }
};
