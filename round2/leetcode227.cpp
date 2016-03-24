
class Solution {
public:
    //encode: <0,+>, <1,->, <2,*> and <3, />
    //ref: https://leetcode.com/discuss/77755/java-easy-version-to-understand
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                int sum = s[i]-'0';
                while (i+1 < s.length() && isdigit(s[i+1])) {
                    sum = 10*sum + s[i+1] - '0';
                    i ++;
                }
                if (!st.empty() && (st.top() == 2 || st.top() == 3)) {
                    int sign = st.top();
                    st.pop();
                    int number = st.top();
                    st.pop();
                    if (sign == 2)
                        st.push(number*sum);
                    else
                        st.push(number/sum);
                }
                else// + and - are processed lastly
                    st.push(sum);
            }
            else if (s[i] == '+')
                st.push(0);
            else if (s[i] == '-')
                st.push(1);
            else if (s[i] == '*')
                st.push(2);
            else if (s[i] == '/')
                st.push(3);
        }
        while (!st.empty()) {
            int a = st.top();
            st.pop();
            
            if (!st.empty()) {
                int sign = st.top();
                st.pop();
                if (sign == 1)  
                    res -= a;
                else
                    res += a;
            }
            else
                res += a;
        }
        return res;
    }
};
