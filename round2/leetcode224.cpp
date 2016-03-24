
class Solution {
public:
    //string, isdigit, isalpha, isalnum
    int calculate(string s) {
        stack<int> st;
        int flag = 1;
        int i = 0;
        int res = 0;
        for (i = 0; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                int sum = s[i] - '0';
                while (i+1 < s.length() && isdigit(s[i+1])) {
                    //sum += sum*10 + s[i+1] - '0'; //WRONG!!!
                    sum = sum*10 + s[i+1] - '0';
                    i ++;
                }
                res += sum*flag;
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
                int a = st.top();//sign
                st.pop();
                int b = st.top();
                st.pop();
                res = res*a + b;
            }
        }
        return res;
    }
};
