
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        int j = 0;
        stack<int> st;
        int sum = 0;
        int sign = 1;//means plus, -1 means minus
        int res = 0;
        for (; j < s.length(); j ++) {
            if (isdigit(s[j])) {
                int curr = s[j] - '0';
                while (j+1 < s.length() && isdigit(s[j+1])) {
                    curr = curr*10 + s[j+1] - '0';
                    j ++;
                }
                if (sign == 1)
                    sum += curr;
                else 
                    sum -= curr;
            }
            else if (s[j] == '+')
                sign = 1;
            else if (s[j] == '-')
                sign = -1;
            else if (s[j] == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[j] == ')') {
                int op = st.top();
                st.pop();
                int prev = st.top();
                st.pop();
                if (op == 1)
                    sum = prev + sum;
                else 
                    sum = prev - sum;
            }
            else
                continue;
        }
        return sum;
    }
};
