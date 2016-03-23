
class Solution {
public:
    
    int calculate(string s) {
        string t = "(";
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] != ' ')
                t += s.substr(i, 1); //take out spaces
        }
        t += ')';//if s="1+ 2", t="(1+2)"
        if (t.length() == 2)
            return 0;
        stack<string> st;
        int i = 0;
        while (i <= t.length() - 1) {
            if (isdigit(t[i])) {
                int start = i;
                while(i+1 <= t.length() - 1 && isdigit(t[i+1])) {
                    i ++;
                }
                string num = t.substr(start, i-start+1);//think about (11+2+3), ((1+2))
                st.push(num);
                i ++;
            }
            else if (t[i] == '+' || t[i] == '-' || t[i] == '(') {
                st.push(string(1,t[i]));
                i ++;
            }
            else if (t[i] == ')') {//think about (11-2+3)
                stack<string> tmp;
                while (st.top() != "(") {
                    string s1 = st.top();
                    tmp.push(s1);
                    st.pop();
                }
                st.pop();//pop '('
                if (!tmp.empty()) {
                    int sum = stoi(tmp.top());
                    tmp.pop();
                    while(!tmp.empty()) {
                        if (tmp.top() == "+") {
                            tmp.pop();
                            string s2 = tmp.top();
                            sum += stoi(s2);
                            tmp.pop();
                        }
                        else if (tmp.top() == "-") {
                            tmp.pop();
                            string s2 = tmp.top();
                            sum -= stoi(s2);
                            tmp.pop();
                        }
                    }
                    st.push(to_string(sum));
                }
                i ++;
            }
        }
        return stoi(st.top());
    }
};
