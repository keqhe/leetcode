
class Solution {
public:
    //<1, +>, <2, ->, <3, *> and <4, />
    int calculate(string s) {
        if (s.empty())
            return 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                int curr = s[i] - '0';
                while (i+1 < s.length() && isdigit(s[i+1])) {
                    curr = curr*10 + s[i+1] - '0';
                    i ++;
                }
                if (!st.empty() && (st.top() == 3 || st.top() == 4)) {
                    int sign = st.top();
                    st.pop();
                    int number = st.top();
                    st.pop();
                    if (sign == 3) {
                        st.push(number*curr);
                    }
                    else if (sign == 4) {
                        st.push(number/curr);
                    }
                }
                else
                    st.push(curr);
            }
            else if (s[i] == '+') {
                st.push(1);
            }
            else if (s[i] == '-') {
                st.push(2);
            }
            else if (s[i] == '*') {
                st.push(3);
            }
            else if (s[i] == '/') {
                st.push(4);
            }
        }
        int res = 0;
        while (!st.empty()) {
            int number = st.top();
            st.pop();
            if (!st.empty()) {
                int sign = st.top();
                st.pop();
                if (sign == 1)
                    res += number;
                else
                    res -= number;
            }
            else
                res += number;
        }
        return res;
    }
};
